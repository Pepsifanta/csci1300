#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main()
{
    int num;
    bSearchTreeType<int> tree1;
    bSearchTreeType<int> tree2;
    bSearchTreeType<int> tree3;

    cout << "Enter numbers ending with -999: ";

    do
    {
        cin >> num;
        if (num != -999)
        {
            tree1.insert(num);
        }
    } while (num != -999);

    cout << "tree1 nodes in postorder: ";
    tree1.postorderTraversal();
    cout << endl;

    // Create tree2 with nodes from tree1 in postorder
    tree1.postorderInsert(tree2);

    cout << "tree2 nodes in preorder: ";
    tree2.preorderTraversal();
    cout << endl;

    // Create tree3 with nodes from tree2 in preorder
    tree2.preorderInsert(tree3);

    cout << "tree3 nodes in inorder: ";
    tree3.inorderTraversal();
    cout << endl;

    // Output heights and number of leaves for each tree
    cout << "tree1 height: " << tree1.treeHeight() << endl;
    cout << "tree1 leaves: " << tree1.treeLeavesCount() << endl;

    cout << "tree2 height: " << tree2.treeHeight() << endl;
    cout << "tree2 leaves: " << tree2.treeLeavesCount() << endl;

    cout << "tree3 height: " << tree3.treeHeight() << endl;
    cout << "tree3 leaves: " << tree3.treeLeavesCount() << endl;

    return 0;
}