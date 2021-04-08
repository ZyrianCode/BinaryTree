#pragma once

template<class T>
class BinaryTreeNode
{
public:
    BinaryTreeNode<T>* Left;
    BinaryTreeNode<T>* Right;
    T val;
    BinaryTreeNode(void) noexcept : Left(nullptr), Right(nullptr) {}
};

