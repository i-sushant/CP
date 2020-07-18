#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> parent;
    void init(int n)
    {
        parent.resize(n + 1);
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
            parent[x] = parent[y] = max(parent[x], parent[y]);
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
    int i;
    dsu G;
    G.init(n);
    for (i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.unify(u, v);
    }
    int q;
    cin >> q;
    for (i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        int x = G.get(u);
        int y = G.get(v);
        if (u < v) {
            if (x == y)
                cout << "TIE";
            else if (x > y)
                cout << u;
            else
                cout << v;
        } else if (u > v) {
            if (x == y)
                cout << "TIE";
            else if (x < y)
                cout << v;
            else
                cout << u;
        }
        cout << endl;
    }
}