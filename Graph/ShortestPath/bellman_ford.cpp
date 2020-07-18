#include <bits/stdc++.h>
using namespace std;
vector<int> bellman_ford(int n, int src, vector<vector<int>> edges)
{
    //minimum distance from source to i
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto x : edges) {
            int from = x[0], to = x[1], weight = x[2];
            if (dist[from] != INT_MAX && dist[to] > dist[from] + weight) {
                //relaxed the edge
                dist[to] = dist[from] + weight;
            }
        }
    }
    //check for negative weight cycle
    for (auto x : edges) {
        int from = x[0], to = x[1], weight = x[2];
        if (dist[from] != INT_MAX && dist[to] > dist[from] + weight) {
            cout << "Negative weight cycle";
            exit(0);
        }
    }
    return dist;
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({ from, to, weight });
    }
    vector<int> dist = bellman_ford(n, 1, edges);
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}
