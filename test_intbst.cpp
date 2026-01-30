// test_intbst.cpp
#include "intbst.h"
#include <iostream>
using namespace std;

int main() {
    IntBST bst1, bst2;

    // 插入数据到 bst1
    int values[] = {64, 128, 8, 512, 256, 32, 16, 4};
    for (int v : values) bst1.insert(v);

    cout << "BST1 Tests:" << endl;

    // 打印
    cout << "Pre-order: ";
    bst1.printPreOrder();
    cout << endl;

    cout << "In-order: ";
    bst1.printInOrder();
    cout << endl;

    cout << "Post-order: ";
    bst1.printPostOrder();
    cout << endl;

    // sum 和 count
    cout << "Sum: " << bst1.sum() << endl;
    cout << "Count: " << bst1.count() << endl;

    // contains 测试
    int testContains[] = {64, 4, 16, 128, 17, 512};
    for (int v : testContains) {
        cout << "Contains " << v << "? " << (bst1.contains(v) ? "Y" : "N") << endl;
    }

    // 前驱和后继
    int testPredSucc[] = {64, 512, 4};
    for (int v : testPredSucc) {
        cout << "Predecessor of " << v << " is: " << bst1.getPredecessor(v) << endl;
        cout << "Successor of " << v << " is: " << bst1.getSuccessor(v) << endl;
    }

    // 删除节点
    int removeVals[] = {4, 64, 128};
    for (int v : removeVals) {
        cout << "Removing " << v << endl;
        bst1.remove(v);
    }

    // 删除后测试 contains
    for (int v : testContains) {
        cout << "Contains " << v << "? " << (bst1.contains(v) ? "Y" : "N") << endl;
    }

    cout << "In-order after deletions: ";
    bst1.printInOrder();
    cout << endl;
    cout << "Pre-order after deletions: ";
    bst1.printPreOrder();
    cout << endl;

    // 测试空树 bst2
    cout << "\nEmpty BST2 Tests:" << endl;
    cout << "Pre-order: ";
    bst2.printPreOrder();
    cout << endl;

    cout << "In-order: ";
    bst2.printInOrder();
    cout << endl;

    cout << "Post-order: ";
    bst2.printPostOrder();
    cout << endl;

    cout << "Sum: " << bst2.sum() << endl;
    cout << "Count: " << bst2.count() << endl;
    cout << "Contains 16? " << (bst2.contains(16) ? "Y" : "N") << endl;

    return 0;
}

