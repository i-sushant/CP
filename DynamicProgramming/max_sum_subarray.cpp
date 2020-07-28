#include <bits/stdc++.h>
using namespace std;

int solveMaxSum(int a[], int n)
{
    int dp[n] = { 0 };
    dp[0] = a[0] < 0 ? 0 : dp[0];
    int maxSoFar = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0) {
            dp[i] = 0;
        }
        maxSoFar = max(dp[i], maxSoFar);
    }
    return maxSoFar;
}
int solveMaxProduct(int a[], int n)
{
    int dp[n] = { 0 };
    dp[0] = a[0];
    int maxSoFar = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] * a[i];
        if (dp[i] < 0 && dp[i - 1] > 0) {
            dp[i] = 0;
        }
        maxSoFar = max(dp[i], maxSoFar);
    }
    return maxSoFar;
}
int main()
{
    int a[5] = { 1, -2, 5, 3, -2 };
    cout << solveMaxSum(a, 5) << endl;
    cout << solveMaxProduct(a, 5);
}
