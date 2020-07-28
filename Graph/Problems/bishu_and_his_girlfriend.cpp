#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ff first
#define ss second
#define ii pair<int, int>
#define vii vector<ii>
#define INF 1e9
using namespace std;
vi ar[1001];
int vis[1001], dist[1001];
void dfs(int node, int d)
{
    vis[node] = 1;
    dist[node] = d;
    for (int child : ar[node]) {
        if (!vis[child]) {
            dfs(child, dist[node] + 1);
        }
    }
}
int main()
{
    int n, q, a, b;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
        cin >> a >> b, ar[a].pb(b), ar[b].pb(a);
    dfs(1, 0);
    cin >> q;
    int ans = -1, min_dist = INF;
    while (q--) {
        int girl_city;
        cin >> girl_city;
        if (dist[girl_city] < min_dist) {
            min_dist = dist[girl_city], ans = girl_city;
        } else if (dist[girl_city] == min_dist && girl_city < ans) {
            ans = girl_city;
        }
    }
    cout << ans << endl;
}