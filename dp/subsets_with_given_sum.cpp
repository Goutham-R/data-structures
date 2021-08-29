#include <bits/stdc++.h>
using namespace std;
int subset_sum_dp(int arr[], int sum, int n)
{
    int t[100][100];
    memset(t, false, sizeof(t));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j >= arr[i - 1])
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}
int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    cout << "No of subsets with given sum : " << subset_sum_dp(set, sum, n) << "\n";
    return 0;
}