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
    int n, q;
    cin >> n >> q;
    int l[q], r[q], c[q];
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> c[i];
    }
    dsu G;
    G.init(n + 2);
    int res[n + 2] = {};
    for (int i = q - 1; i >= 0; i--) {
        //rightmost non colored index
        int idx = G.get(l[i]);
        while (idx <= r[i]) {
            res[idx] = c[i];
            G.unify(idx, idx + 1);
            //rightmost
            idx = G.get(idx);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << endl;
    }
}