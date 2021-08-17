#pragma once
#include <iostream>
#define in(x) std::cin >> x;
#define out(x) std::cout << x << std::endl;
class BST
{
    int data;
    BST *left, *right;

public:
    BST();
    BST(int);
    BST *insert0(BST *, int);
    void inorder(BST *);
};
BST::BST() : data(0), left(NULL), right(NULL){};
BST::BST(int value)
{
    data = value;
    left = right = NULL;
}
BST *BST::insert0(BST *root, int value)
{
    if (!root)
    {
        BST *next = new BST(value);
        return next;
    }
    if (value > root->data)
    {
        root->right = insert0(root->right, value);
    }
    else
    {
        root->left = insert0(root->left, value);
    }
    return root;
}
void BST::inorder(BST *root)
{
    if (!root)
        return;
    inorder(root->left);
    out(root->data);
    inorder(root->right);
}