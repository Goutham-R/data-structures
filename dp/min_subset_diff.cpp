#include <bits/stdc++.h>
using namespace std;
int min_subset_diff(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    bool t[100][100];
    vector<int> ans;
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
    for (int i = 0; i < sum / 2; i++)
    {
        if (t[n][i])
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    return sum - 2 * (*(ans.end() - 1));
}
int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between 2 sets is " << min_subset_diff(arr, n) << "\n";
    return 0;
}
