#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> weight(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++) {
        int from, to, wt;
        cin >> from >> to >> wt;
        weight[from][to] = wt;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                weight[i][j] = min(weight[i][j], weight[i][k] + weight[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << weight[i][j] << " ";
        }
        cout << endl;
    }
}