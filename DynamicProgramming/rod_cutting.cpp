#include <bits/stdc++.h>
using namespace std;
int solveTopDown(int p[], int n, int l, int dp[])
{
    if (l == 0)
        return 0;
    if (dp[l] != 0)
        return dp[l];
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (l - i >= 0) {
            ans = max(solveTopDown(p, n, l - i, dp) + p[i], ans);
        }
    }
    return dp[l] = ans;
}
int solveBottomUp(int p[], int n, int l)
{
    int dp[100] = {};
    if (l == 0)
        return 0;
    for (int i = 1; i <= l; i++) {
        int ans = INT_MIN;
        for (int j = 1; j <= i; j++) {
            ans = max(p[j] + dp[i - j], ans);
        }
        dp[i] = ans;
    }
    return dp[l];
}
int main()
{
    int dp[100] = { 0 };
    int p[5] = { INT_MIN, 1, 4, 3, 5 };
    cout << solveTopDown(p, 5, 4, dp) << endl;
    cout << solveBottomUp(p, 5, 4) << endl;
}