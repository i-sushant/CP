#include <bits/stdc++.h>
#define ll long long int
#define n 100005
using namespace std;
ll dp[n];
ll height[n];
ll solve(int N, int k)
{
    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        dp[i] = INT_MAX;
        for (int j = i - 1; j >= 1 && (i - j) <= k; j--) {
            ll opt1 = abs(height[i] - height[j]) + dp[j];
            dp[i] = min(dp[i], opt1);
        }
    }
    return dp[N];
}

int main()
{
    memset(dp, 0, sizeof dp);
    memset(height, 0, sizeof height);
    int N, k;
    cin >> N >> k;
    for (int i = 1; i <= N; i++) {
        cin >> height[i];
    }
    cout << solve(N, k);
}