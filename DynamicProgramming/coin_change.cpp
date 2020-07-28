#include <bits/stdc++.h>
using namespace std;
int solveTopDown(int amt, int coins[], int n, int dp[])
{
    if (amt == 0)
        return 0;
    if (dp[amt] != 0) {
        return dp[amt];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (amt - coins[i] >= 0) {
            ans = min(solveTopDown(amt - coins[i], coins, n, dp) + 1, ans);
        }
    }
    dp[amt] = ans;
    return dp[amt];
}
int solveBottomUp(int amt, int coins[], int n)
{
    if (amt == 0)
        return 0;
    int dp[100] { 0 };
    for (int i = 1; i <= amt; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    return dp[amt];
}
int main()
{
    int dp[100] = { 0 };
    int coins[3] = { 1, 7, 10 };
    cout << solveTopDown(15, coins, 3, dp) << endl;
    cout << solveBottomUp(15, coins, 3);
}