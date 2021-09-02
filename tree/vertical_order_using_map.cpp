#include <bits/stdc++.h>
#include "defn.h"
map<int, vactor<int>> m;
void vertical_order(BST *root, int hd)
{
    if (root == NULL)
        return;
    m[hd].push_back(root->data);
    vertical_order(root->left, hd - 1);
    vertical_order(root->right, hd + 1);
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
    int hd = 0;
    getVerticalOrder(root, hd, m);
    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}