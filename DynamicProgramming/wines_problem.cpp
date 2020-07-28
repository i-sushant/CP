#include <bits/stdc++.h>
using namespace std;
int solveTopDown(int i, int j, vector<vector<int>>& dp, int p[], int y)
{
    if (i > j) {
        return 0;
    }
    if (dp[i][j] != 0)
        return dp[i][j];
    int choice_1 = p[i] * y + solveTopDown(i + 1, j, dp, p, y + 1);
    int choice_2 = p[j] * y + solveTopDown(i, j - 1, dp, p, y + 1);

    return dp[i][j] = max(choice_1, choice_2);
}

int main()
{
    vector<vector<int>> dp(100, vector<int>(100, 0));
    int p[3] = { 2, 3, 5 };
    solveTopDown(0, 2, dp, p, 1);
    cout << dp[0][2] << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}