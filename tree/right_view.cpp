#inclide < bits / stdc++.h>
#include "defn.h"
using namespace std;
int max_level = 0;
void right_view(BST *root, int level)
{
    if (root == NULL)
        return;
    if (max_level < level)
    {
        out(root->data);
        max_level = level;
    }
    right_view(root->right, level + 1);
    right_view(root->left, level + 1);
}
void main()
{
    BST b, *root = NULL;
    root = b.insert0(root, 50);
    b.insert0(root, 30);
    b.insert0(root, 20);
    b.insert0(root, 40);
    b.insert0(root, 70);
    b.insert0(root, 60);
    b.insert0(root, 80);
    right_view(root, 1)
}