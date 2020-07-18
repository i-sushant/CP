#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> parent, size;
    int total_comp;
    void init(int n)
    {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            size[i] = 1;
        }
        total_comp = n;
    }
    int get_superparent(int x)
    {
        if (x == parent[x])
            return x;
        //path compression
        return parent[x] = get_superparent(parent[x]);
    }
    void unify(int x, int y)
    {
        int superparent_x = get_superparent(x);
        int superparent_y = get_superparent(y);
        if (superparent_x != superparent_y) {
            parent[superparent_x] = superparent_y;
            size[superparent_y] += size[superparent_x];
            size[superparent_x] = 0;
            total_comp--;
        }
    }
} G;
void solve()
{
    int i, j, n, m, ans = 0;
    cin >> n >> m;
    G.init(n);
    for (i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        G.unify(x, y);
    }
    for (int i = 0; i < n; i++) {
        // i is considered as x
        int superparent_i = G.get_superparent(i);
        ans += n - G.size[superparent_i];
    }
    cout << (ans / 2);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    solve();
}