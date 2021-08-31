#include <bits/stdc++.h>
using namespace std;

int unbounded_knapsack(int wt[], int val[], int w, int n)
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
                t[i][j] = max(val[i - 1] + t[i][j - wt[j - 1]], t[i - 1][j]);
            /* Even after an element in the array is chosen, we can choose it again if we want.
                This is the only change when compared to 0/1 knapsack*/
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
    cout << unbounded_knapsack(wt, val, W, n);
    return 0;
}
