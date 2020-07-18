#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> p;
    void init(int n)
    {
        p.clear();
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int get(int x)
    {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    void unify(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
        }
    }
} G;
void solve()
{
    int i, j, n, m, ans = 0;
    cin >> n >> m;
    G.init(n);
    bool cycle = 0;
    for (i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (G.get(x) != G.get(y)) {
            //different component
            G.unify(x, y);
        } else {
            //same component
            //there was a path from x to y
            cycle = 1;
        }
    }
    if (cycle)
        cout << "Cycle in the graph";
    else
        cout << "No cycle";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}