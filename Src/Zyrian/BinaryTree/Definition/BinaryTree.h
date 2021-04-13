#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "BinaryTreeNode.h"

using std::forward;
using std::cout;
using std::endl;

template<class T>
class BinaryTree
{
private:
    BinaryTreeNode<T>* TreeRoot;
    int PosCounter = 0;
public:
    BinaryTree(void) noexcept : TreeRoot(nullptr){}
    ~BinaryTree() { DestroyTree(); }

    BinaryTree(const BinaryTree&) = delete;
    BinaryTree& operator = (const BinaryTree&) = delete;

    void Insert(T value);
    void Add(T&& value);
    void InsertUnique(const T& value);

    void DestroyTree();

    void PreorderPrint();

    void InorderPrint();

    void PostorderPrint();

    T PopMin(void) noexcept;
    T PopMax(void) noexcept;
    BinaryTreeNode<T>* Search(T value);

    bool IsEmpty(void) const noexcept;

private:

    void Destroy_tree(BinaryTreeNode<T>* Branch);

    void erase(BinaryTreeNode<T>** RootPointer, BinaryTreeNode<T>* Ptr) noexcept;

    void Insert(T value, BinaryTreeNode<T>* Branch);

    BinaryTreeNode<T>* Search(T value, BinaryTreeNode<T>* Branch);

    BinaryTreeNode<T>** Find(const T& value) noexcept;

    void Preorder_print(BinaryTreeNode<T>* Branch);

    void Inorder_print(BinaryTreeNode<T>* Branch);

    void Postorder_print(BinaryTreeNode<T>* Branch);

};
