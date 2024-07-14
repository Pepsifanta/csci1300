//Header File Binary Tree
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>

using namespace std;

//Definition of the node
template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;
};


template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType>
{
public:
    // Rest of the member functions...
    virtual bool search(const elemType& searchItem) const = 0;
    virtual void insert(const elemType& insertItem) = 0;
    virtual void deleteNode(const elemType& deleteItem) = 0;

    void postorderInsert(binaryTreeType<elemType>& targetTree);
    void preorderInsert(binaryTreeType<elemType>& targetTree);

private:
    // Add the correct function definitions
    void postorderInsertHelper(binaryTreeType<elemType>& targetTree, nodeType<elemType>*& targetNode, nodeType<elemType>*& sourceNode);
    void preorderInsertHelper(binaryTreeType<elemType>& targetTree, nodeType<elemType>*& targetNode, nodeType<elemType>*& sourceNode);

    // ...
};
// Rest of the implementation...

#endif
