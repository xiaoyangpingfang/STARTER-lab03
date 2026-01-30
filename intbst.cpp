// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
	root = 0;
}

// destructor deletes all nodes
IntBST::~IntBST() {
	clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
	if(n==0) return;
	clear(n->left);
	clear(n->right);
	delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if(root==0){
    	root = new Node(value);
    	return true;
	}
	return insert(value,root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if(value==n->info){
    	return false;
	}
	else if(value<n->info){
		if(n->left==0){
			n->left=new Node(value);
			n->left->parent=n;
			return true;
		}
		return insert(value, n->left);
	}
	else{
		if(n->right==0){
			n->right=new Node(value);
			n->right->parent=n;
			return true;
		}
		return insert(value, n->right);
	}
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
	if(n==0) return;
	cout<<n->info<<" ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
	if(n==0) return;
    printInOrder(n->left);
    cout<<n->info<<" ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
	if(n==0) return;
	printPostOrder(n->left);
    printPostOrder(n->right);
    cout<<n->info<<" ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if(n==0) return 0;
    return n->info + sum(n->left) + sum(n->right);
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
   if(n==0) return 0;
   return 1+count(n->left)+count(n->right);
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if(n==0) return 0;
    if(value==n->info) return n;
    if(value< n->info) return getNodeFor(value, n->left);
    else return getNodeFor(value, n->right);
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return getNodeFor(value,root) !=0;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* target = getNodeFor(value, root);
    if(target==0) return 0;
    if(target->left!=0){
    	Node*p = target->left;
    	while(p->right!=0) p=p->right;
    	return p;
	}
	Node*p = target;
	while(p->parent!=0&&p->parent->right!=p) p=p->parent;
	return p->parent;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* node = getPredecessorNode(value);
    if(node==0) return 0;
    return node->info;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* target=getNodeFor(value,root);
    if(!target) return 0;
    if(target->right !=0){
    	Node* p=target->right;
    	while(p->left!=0){
    		p=p->left;
		}
		return p;
	}
	Node* p=target;
	while(p->parent!=0&&p->parent->left!=p) p=p->parent;
	return p->parent;
    
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* node=getSuccessorNode(value);
    if(node==0) return 0;
    return node->info;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    Node* target=getNodeFor(value, root);
    if(!target) return false;
    if(target->left&&target->right){
    	Node* succ = getSuccessorNode(value);
    	target->info = succ->info;
    	target=succ;
	}
	Node* child=nullptr;
	if(target->left) child=target->left;
	else if(target->right) child=target->right;
	if(child) child->parent=target->parent;
	if(!target->parent) root=child;
	else if(target->parent->left==target) target->parent->left=child;
	else target->parent->right=child;
	delete target;
	return true;
}
