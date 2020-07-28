#include <bits/stdc++.h>
using namespace std;
vector<int> gr[100001];
int vis[100001];
void dfs(int node)
{
    vis[node] = 1;
    for (auto x : gr[node]) {
        if (!vis[x]) {
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            count++;
        }
    }
    if (count == 1 && m == n - 1)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}