#include <bits/stdc++.h>
using namespace std;
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
    vector<pair<int, int>> graph[n + 1];
    int vis[n + 1] = {};
    //vis means included in my MST
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({ y, w });
        graph[y].push_back({ x, w });
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 }); // weight, node
    long long int mst = 0;
    while (!pq.empty()) {
        pair<int, int> best = pq.top();
        pq.pop();
        int weight = best.first;
        int to = best.second;
        //not an active edge
        if (vis[to]) {
            continue;
        }
        mst += weight;
        vis[to] = 1;
        //to vertex is visited
        for (auto x : graph[to]) {
            if (vis[x.first] == 0) { // x.first is not visited
                pq.push({ x.second, x.first });
            }
        }
    }
    cout << mst << endl;
}