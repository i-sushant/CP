#include <bits/stdc++.h>
using namespace std;
const int n = 1005;
int boy_start[n][n];
int boy_end[n][n];
int girl_start[n][n];
int girl_end[n][n];
int calorie[n][n];
int solve(int M, int N)
{
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            boy_start[i][j] = calorie[i][j] + max(boy_start[i - 1][j], boy_start[i][j - 1]);
        }
    }
    for (int i = M; i >= 1; i--) {
        for (int j = 1; j <= N; j++) {
            girl_start[i][j] = calorie[i][j] + max(girl_start[i + 1][j], girl_start[i][j - 1]);
        }
    }
    for (int i = M; i >= 1; i--) {
        for (int j = N; j >= 1; j--) {
            boy_end[i][j] = calorie[i][j] + max(boy_end[i + 1][j], boy_end[i][j + 1]);
        }
    }
    for (int i = 1; i <= M; i++) {
        for (int j = N; j >= 1; j--) {
            girl_end[i][j] = calorie[i][j] + max(girl_end[i - 1][j], girl_end[i][j + 1]);
        }
    }
    int ans = 0;
    for (int i = 2; i < M; i++) {
        for (int j = 2; j < N; j++) {
            int ans1 = boy_start[i][j - 1] + boy_end[i][j + 1] + girl_start[i + 1][j] + girl_end[i - 1][j];
            int ans2 = boy_start[i - 1][j] + boy_end[i + 1][j] + girl_start[i][j - 1] + girl_end[i][j + 1];
            ans = max(ans, max(ans1, ans2));
        }
    }
    return ans;
}
int main()
{
    memset(boy_start, 0, sizeof(boy_start));
    memset(boy_end, 0, sizeof(boy_end));
    memset(girl_start, 0, sizeof(girl_start));
    memset(girl_end, 0, sizeof(girl_end));
    memset(calorie, 0, sizeof(calorie));
    int M, N;
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> calorie[i][j];
        }
    }
    cout << solve(M, N);
    return 0;
}
