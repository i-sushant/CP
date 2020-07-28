#include <bits/stdc++.h>
using namespace std;
int dp[5][5];
void solve()
{
    dp[0][0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 && j == 0)
                continue;
            int sum = 0;
            for (int k = 0; k <= i; k++) {
                sum += dp[k][j];
            }

            for (int k = 0; k <= j; k++) {
                sum += dp[i][k];
            }
            dp[i][j] = sum;
        }
    }
}
int main()
{
    memset(dp, 0, sizeof(dp));
    solve();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}