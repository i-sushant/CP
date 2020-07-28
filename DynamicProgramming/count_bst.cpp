#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll solve(int n, ll dp[])
{
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != 0) {
        return dp[n];
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (n - i >= 0)
            sum += solve(i - 1, dp) * solve(n - i, dp);
    }
    return dp[n] = sum;
}
int main()
{
    ll dp[101] = { 0 };
    cout << solve(3, dp);
}