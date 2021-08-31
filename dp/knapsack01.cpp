#include <bits/stdc++.h>
using namespace std;
// 0/1 Knpasack without DP
int knapsack(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
        return 0;
    if (wt[n - 1] <= w)
        return (max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1)));
    return (knapsack(wt, val, w, n - 1));
}
int knapsack_dp(int wt[], int val[], int w, int n)
{
    int t[300][52];
    memset(t, -1, sizeof(t));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[j - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][w];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(wt, val, W, n) << "\n";
    cout << knapsack_dp(wt, val, W, n);
    return 0;
}
