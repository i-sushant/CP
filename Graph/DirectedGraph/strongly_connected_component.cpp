#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 100005, M = 25;
vector<int> graph[N], rev_graph[N];
vector<int> order;
int vis[N], comp[N];
vector<int> in_comp[N];
//Also know as kosaraju's algorithm

void dfs(int curr)
{
    vis[curr] = 1;
    for (auto nbr : graph[curr]) {
        if (!vis[nbr])
            dfs(nbr);
    }
    order.pb(curr);
}
void dfs_reverse(int curr, int col)
{
    comp[curr] = col;
    in_comp[col].pb(curr);
    vis[curr] = 1;
    for (auto nbr : rev_graph[curr]) {
        if (!vis[nbr]) {
            dfs_reverse(nbr, col);
        }
    }
}
void solve()
{
    int n, m, ans;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
        rev_graph[y].pb(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    int col = 1;
    for (int i = n; i >= 1; i--) {
        if (!vis[order[i]]) {
            dfs_reverse(order[i], col);
            col++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " -> " << comp[i] << endl;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    solve();
}