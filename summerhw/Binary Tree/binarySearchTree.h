#ifndef H_binarySearchTree
#define H_binarySearchTree

#include <iostream>
#include "binaryTree.h"

// Forward declaration of binaryTreeType and friend function declarations
template <class elemType>
class binaryTreeType;
template <class elemType>
void preorderInsertHelper(bSearchTreeType<elemType>& targetTree, nodeType<elemType>*& targetNode, nodeType<elemType>*& sourceNode);
template <class elemType>
void postorderInsertHelper(bSearchTreeType<elemType>& targetTree, nodeType<elemType>*& targetNode, nodeType<elemType>*& sourceNode);


template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType>
{
    
protected:
    nodeType<elemType>* root; // Add this protected data member

public:
    // Implementation of the missing member functions
    virtual bool search(const elemType& searchItem) const override;
    virtual void insert(const elemType& insertItem) override;
    virtual void deleteNode(const elemType& deleteItem) override;

    void postorderInsert(binaryTreeType<elemType>& targetTree);
    void preorderInsert(binaryTreeType<elemType>& targetTree);

    // Rest of the member functions...
};

// Implementation of member functions...

template <class elemType>
bool bSearchTreeType<elemType>::search(const elemType& searchItem) const
{
    // Simple search implementation for demonstration purposes
    return binaryTreeType<elemType>::search(searchItem);
}

template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)
{
    this->root = this->insert(this->root, insertItem); // Use this->root
}

template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem)
{
    // Implementation of the deleteNode function for the binary search tree
    // Add your code here to delete the specified node
}

template <class elemType>
void bSearchTreeType<elemType>::postorderInsert(binaryTreeType<elemType>& targetTree)
{
    postorderInsertHelper(targetTree, targetTree.root, this->root); // Use this->root
}

template <class elemType>
void bSearchTreeType<elemType>::postorderInsertHelper(binaryTreeType<elemType>& targetTree, nodeType<elemType>*& targetNode, nodeType<elemType>*& sourceNode)
{
    if (sourceNode != nullptr)
    {
        // First, recursively insert nodes from the left subtree
        postorderInsertHelper(targetTree, targetNode, sourceNode->lLink);

        // Then, recursively insert nodes from the right subtree
        postorderInsertHelper(targetTree, targetNode, sourceNode->rLink);

        // Finally, insert the current node into the target tree
        targetNode = targetTree.insert(targetNode, sourceNode->info);
    }
}

template <class elemType>
void bSearchTreeType<elemType>::preorderInsert(binaryTreeType<elemType>& targetTree)
{
    preorderInsertHelper(targetTree, targetTree.root, this->root); // Use this->root
}

template <class elemType>
void bSearchTreeType<elemType>::preorderInsertHelper(binaryTreeType<elemType>& targetTree, nodeType<elemType>*& targetNode, nodeType<elemType>*& sourceNode)
{
    if (sourceNode != nullptr)
    {
        // First, insert the current node into the target tree
        targetNode = targetTree.insert(targetNode, sourceNode->info);

        // Then, recursively insert nodes from the left subtree
        preorderInsertHelper(targetTree, targetNode, sourceNode->lLink);

        // Finally, recursively insert nodes from the right subtree
        preorderInsertHelper(targetTree, targetNode, sourceNode->rLink);
    }
}

#endif
