#include <bits/stdc++.h>
using namespace std;

int min_coins(int coin[], int change, int n)
{
    int t[300][52];
    memset(t, -1, sizeof(t));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < change + 1; j++)
        {
            if (j == 0)
                t[i][j] = 0;
            if (i == 0)
                t[i][j] = INT_MAX - 1;
        }
    }
    for (int j = 1; j < change + 1; j++)
    {
        if (coin[0] % j != 0)
            t[1][j] = INT_MAX - 1;
        else
            t[1][j] = coin[0] / j;
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < change + 1; j++)
        {
            if (coin[i - 1] <= j)
                t[i][j] = min(t[i][j - coin[j - 1]] + 1, t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][change];
}

int main()
{

    int coin[] = {10, 20, 30};
    int change = 50;
    int n = sizeof(coin) / sizeof(coin[0]);
    cout << min_coins(coin, change, n);
    return 0;
}
