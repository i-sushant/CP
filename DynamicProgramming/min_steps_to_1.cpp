#include <bits/stdc++.h>
using namespace std;
int solveTopDown(int n, int dp[])
{
    if (n == 1) {
        return 0;
    }
    if (dp[n] != 0)
        return dp[n];
    int steps_2 = n % 2 == 0 ? solveTopDown(n / 2, dp) : INT_MAX;
    int steps_3 = n % 3 == 0 ? solveTopDown(n / 3, dp) : INT_MAX;
    int steps_1 = solveTopDown(n - 1, dp);
    return dp[n] = 1 + min(steps_1, min(steps_2, steps_3));
}
int solveBottomUp(int n)
{
    int dp[100] = { 0 };
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        int x = i % 2 == 0 ? dp[i / 2] : INT_MAX;
        int y = i % 3 == 0 ? dp[i / 3] : INT_MAX;
        int z = dp[i - 1];
        dp[i] = 1 + min(x, min(y, z));
    }
    return dp[n];
}
int main()
{
    int dp[100] = { 0 };
    cout << solveTopDown(99, dp) << endl;
    cout << solveBottomUp(99);
}