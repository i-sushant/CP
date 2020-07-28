#include <bits/stdc++.h>
#define ll long long int
#define n 100005
using namespace std;
ll dp[n];
ll height[n];
ll solve(int N)
{
    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        ll opt1 = abs(height[i] - height[i - 1]) + dp[i - 1];
        ll opt2 = (i == 2) ? INT_MAX : abs(height[i] - height[i - 2]) + dp[i - 2];
        dp[i] = min(opt1, opt2);
    }
    return dp[N];
}
int main()
{
    memset(dp, 0, sizeof dp);
    memset(height, 0, sizeof height);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> height[i];
    }
    cout << solve(N);
}