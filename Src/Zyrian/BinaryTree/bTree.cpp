#include <iostream>
#include "Src/Zyrian/BinaryTree/Implementation/BinaryTree.hpp"

int main()
{
    BinaryTree<int> a;
    /*a.InsertUnique(5);
    a.InsertUnique(4);
    a.InsertUnique(6);
    a.InsertUnique(2);
    a.InsertUnique(3);*/

    a.Insert(5);
    a.Insert(4);
    a.Insert(6);
    a.Insert(6);
    a.InorderPrint();
    cout << a.Search(6);

}

