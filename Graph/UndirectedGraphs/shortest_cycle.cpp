#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 100005, M = 25;
vector<int> graph[N];
void bfs(int src, int n, int& ans)
{
    vector<int> dis(n + 1, INT_MAX);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto nbr : graph[curr]) {
            if (dis[nbr] == INT_MAX) {
                //neighbour not visited
                dis[nbr] = dis[curr] + 1;
                q.push(nbr);
            } else if (dis[nbr] >= dis[curr]) {
                //back edge is encountered
                ans = min(ans, dis[nbr] + dis[curr] + 1);
            }
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
        graph[y].pb(x);
    }
    ans = n + 1;
    for (int i = 1; i <= n; i++) {
        bfs(i, n, ans);
    }
    if (ans == n + 1) {
        cout << "No cycle" << endl;
    } else {
        cout << "Shortest cycle is " << ans << endl;
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