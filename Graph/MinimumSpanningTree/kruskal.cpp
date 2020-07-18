#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> parent;
    void init(int n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int get(int x)
    {
        return (x == parent[x] ? x : parent[x] = get(parent[x]));
    }
    void unify(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x != y) {
            parent[x] = y;
        }
    }
};
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
        int x, y, w;
        cin >> x >> y >> w;
        edges[i] = { w, x, y };
    }
    sort(edges.begin(), edges.end());
    dsu G;
    G.init(n);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x = edges[i][1];
        int y = edges[i][2];
        int w = edges[i][0];
        if (G.get(x) != G.get(y)) {
            //can take this edge
            G.unify(x, y);
            //include all the edge which doesn't result in a cycle
            ans += w;
        }
    }
    cout << ans << endl;
}