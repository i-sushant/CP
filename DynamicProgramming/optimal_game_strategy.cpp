#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int n, int i, int j, vector<vector<int>>& dp)
{
    if (i > j)
        return 0;
    if (j == i + 1)
        return max(a[i], a[j]);
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = max(a[i] + min(solve(a, n, i + 2, j, dp), solve(a, n, i + 1, j - 1, dp)),
        a[j] + min(solve(a, n, i, j - 2, dp), solve(a, n, i + 1, j - 1, dp)));
    return dp[i][j];
}
int main()
{
    int a[] = { 5, 3, 7, 10 };
    vector<vector<int>> dp(4, vector<int>(4, -1));
    cout << solve(a, 4, 0, 3, dp);
}