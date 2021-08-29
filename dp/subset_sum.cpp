#include <bits/stdc++.h>
using namespace std;
//Without dp
bool subset_sum(int arr[], int sum, int n)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (sum > arr[n - 1])
        return (subset_sum(arr, sum - arr[n - 1], n - 1) || subset_sum(arr, sum, n - 1));
    else
        return subset_sum(arr, sum, n - 1);
}
//With dp
bool subset_sum_dp(int arr[], int sum, int n)
{
    bool t[100][100];
    memset(t, false, sizeof(t));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j >= arr[i - 1])
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
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
    if (subset_sum(set, sum, n) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    if (subset_sum_dp(set, sum, n) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}