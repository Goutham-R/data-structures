#inclide < bits / stdc++.h>
#include "defn.h"
using namespace std;
void level_order(BST *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        out(root->data);
    else
    {
        level_order(root->left, level - 1);
        level_order(root->right, level - 1);
    }
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
    for (int i = 0; i < b.height_tree(root))
    {
        level_order(root, i);
    }
}