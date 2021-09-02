#include <bits/stdc++.h>
#include "defn.h"
using namespace std;

void level_order_queue(BST *root)
{
    if (root == NULL)
        return;
    queue<BST *> q;
    q.push(root);
    while (!q.empty())
    {
        int nc = q.size();
        while (nc > 0)
        {
            BST *temp = q.front();
            out(temp->data);
            q.pop();
            if (root->left != NULL)
                q.push(root->left);
            if (root->right != NULL)
                q.push(root->right);
            nc--;
        }
    }
}

void level_order(BST *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        out(root->data);
    if (level > 1)
    {
        level_order(root->left, level - 1);
        level_order(root->right, level - 1);
    }
}
int main()
{
    BST b, *root = NULL;
    root = b.insert0(root, 50);
    b.insert0(root, 30);
    b.insert0(root, 20);
    b.insert0(root, 40);
    b.insert0(root, 70);
    b.insert0(root, 60);
    b.insert0(root, 80);
    for (int i = 1; i <= b.height_tree(root); i++)
    {
        level_order(root, i);
    }
    out("------------------");
    level_order_queue(root);
    return 0;
}