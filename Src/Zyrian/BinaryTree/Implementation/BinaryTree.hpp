#include "Src/Zyrian/BinaryTree/Definition/BinaryTree.h"

template<class T> //public
void BinaryTree<T>::Insert(T value)
{
    if (TreeRoot != nullptr) {
        Insert(value, TreeRoot);
    }
    else
    {
        TreeRoot = new BinaryTreeNode<T>();
        TreeRoot->val = value;
        TreeRoot->Left = nullptr;
        TreeRoot->Right = nullptr;
    }
}

template<class T> //public 
void BinaryTree<T>::Add(T&& value) //for unique values
{
    BinaryTreeNode<T>* Ptr;
    if (TreeRoot == nullptr) {
        TreeRoot = new BinaryTreeNode<T>();
        TreeRoot->val = std::forward<T>(value);
    }
    else
    {
        BinaryTreeNode<T>** RootPtr = Find(value);
        if (TreeRoot != nullptr)
        {
            Ptr = new BinaryTreeNode<T>();
            Ptr->val = std::forward<T>(value);
            *RootPtr = Ptr;
        }
    }
}

template<class T> //public
void BinaryTree<T>::InsertUnique(const T& value)
{
    BinaryTreeNode<T>* Ptr;
    if (TreeRoot == nullptr)
    {
        TreeRoot = new BinaryTreeNode<T>();
        TreeRoot->val = value;
    }
    else
    {
        BinaryTreeNode<T>** RootPtr = Find(value);
        if (TreeRoot != nullptr)
        {
            Ptr = new BinaryTreeNode<T>();
            Ptr->val = value;
            *RootPtr = Ptr;
        }
    }
}

template<class T> //public
void BinaryTree<T>::DestroyTree()
{
    Destroy_tree(TreeRoot);
    TreeRoot = nullptr;
}

template<class T> //public
void BinaryTree<T>::PreorderPrint()
{
    Preorder_print(TreeRoot);
    cout <<endl;
}

template<class T> //public
void BinaryTree<T>::InorderPrint()
{
    Inorder_print(TreeRoot);
    cout << endl;
}

template<class T> //public
void BinaryTree<T>::PostorderPrint()
{
    Postorder_print(TreeRoot);
    cout << endl;
}

template<class T> //public
T BinaryTree<T>::PopMin(void) noexcept
{
    T value;
    BinaryTreeNode<T>** RootPtr = &TreeRoot, * Ptr = TreeRoot;

    if (TreeRoot != nullptr)
    {
        while (Ptr->Left != nullptr)
        {
            RootPtr = &Ptr->Left;
            Ptr = Ptr->Left;
        }
    }
    if (Ptr != nullptr)
    {
        value = std::forward<T>(Ptr->val);
        erase(RootPtr, Ptr);
    }
    return std::forward<T>(value);
}

template<class T> //public
T BinaryTree<T>::PopMax(void) noexcept
{
    T value;
    BinaryTreeNode<T>** RootPtr = &TreeRoot, * Ptr = TreeRoot;
    if (TreeRoot != nullptr)
    {
        while (Ptr->Right != nullptr)
        {
            RootPtr = &Ptr->Right;
            Ptr = Ptr->Right;
        }
    }
    if (Ptr != nullptr)
    {
        value = std::forward<T>(value);
        erase(RootPtr, Ptr);
    }
    return std::forward<T>(value);
}

template<class T> //public
BinaryTreeNode<T>* BinaryTree<T>::Search(T value)
{
    return (BinaryTreeNode<T>*)Search(value, TreeRoot);
}

template<class T> //public
bool BinaryTree<T>::IsEmpty(void) const noexcept
{
    return (TreeRoot == nullptr);
}



template<class T>  //private
void BinaryTree<T>::Insert(T value, BinaryTreeNode<T>* Branch)
{
    if (value < Branch->val) {
        if (Branch->Left != nullptr) {
            Insert(value, Branch->Left);
        }
        else {
            Branch->Left = new BinaryTreeNode<T>();
            Branch->Left->val = value;
            Branch->Left->Left = nullptr;
            Branch->Left->Right = nullptr;
        }
    }
    else if (value >= Branch->val) {
        if (Branch->Right != nullptr) {
            Insert(value, Branch->Right);
        }
        else {
            Branch->Right = new BinaryTreeNode<T>();
            Branch->Right->val = value;
            Branch->Right->Right = nullptr;
            Branch->Right->Left = nullptr;
        }
    }

}

template<class T> //private
BinaryTreeNode<T>* BinaryTree<T>::Search(T value, BinaryTreeNode<T>* Branch)
{
    if (Branch != nullptr)
    {
        if (value == Branch->val){
            return Branch;
        }
        if (value < Branch->val){
            return Search(value, Branch->Left);
        }
        else{
            return Search(value, Branch->Right);
        }
    }
    else{ return NULL; }
}

template<class T> //private
BinaryTreeNode<T>** BinaryTree<T>::Find(const T& value) noexcept
{
    BinaryTreeNode<T>** RootPtr = &TreeRoot, * Ptr = TreeRoot;
    while (Ptr != nullptr)
    {
        if (value == Ptr->val) {
            return nullptr;
        }
        else if (value < Ptr->val)
        {
            RootPtr = &Ptr->Left;
            Ptr = Ptr->Left;
        }
        else
        {
            RootPtr = &Ptr->Right;
            Ptr = Ptr->Right;
        }
    }
    return RootPtr;
}

template<class T> //private
void BinaryTree<T>::Preorder_print(BinaryTreeNode<T>* Branch)
{
    if (Branch != nullptr) {
        cout << Branch->val << ",";
        Inorder_print(Branch->Left);
        Inorder_print(Branch->Right);
    }
}

template<class T> //private
void BinaryTree<T>::Inorder_print(BinaryTreeNode<T>* Branch)
{
    if (Branch != nullptr) {
        PosCounter += 8;
        Inorder_print(Branch->Right); //left
     
        for (int i = 0; i < PosCounter; i++)
        {
            cout << " ";
        }
        cout << Branch->val << endl;

        Inorder_print(Branch->Left); //right
        PosCounter -= 8;
    }
}

template<class T> //private
void BinaryTree<T>::Postorder_print(BinaryTreeNode<T>* Branch)
{
    if (Branch != nullptr) {
        Inorder_print(Branch->Right); //left
        Inorder_print(Branch->Left); //right
        PosCounter += 8;
       
        cout << Branch->val << ",";
    }
}

template<class T> //private
void BinaryTree<T>::Destroy_tree(BinaryTreeNode<T>* Branch)
{
    if (Branch != nullptr) {
        if (Branch->Left != nullptr)
        {
            Destroy_tree(Branch->Left);
        }
        if (Branch->Right != nullptr)
        {
            Destroy_tree(Branch->Right);
        }
        delete Branch;
    }
}

template<class T> //private
void BinaryTree<T>::erase(BinaryTreeNode<T>** RootPointer, BinaryTreeNode<T>* Ptr) noexcept
{
    if (Ptr->Right == nullptr) { *RootPointer = Ptr->Left; }
    else
    {
        BinaryTreeNode<T>* Root = Ptr->Right;
        if (Root->Left == nullptr)
        {
            Root->Left = Ptr->Left;
            *RootPointer = Root;
        }
        else
        {
            BinaryTreeNode<T>* root = Root->Left;
            while (root->Left != nullptr)
            {
                Root = root;
                root = Root->Left;
            }
            Root->Left = root->Right;
            root->Left = Ptr->Left;
            root->Right = Ptr->Right;
            *RootPointer = root;
        }
    }
    delete Ptr;
}
