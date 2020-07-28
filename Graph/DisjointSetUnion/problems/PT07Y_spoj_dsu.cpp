#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> p;
    int cmp;
    void init(int n)
    {
        cmp = n;
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
    }
    int get(int x)
    {
        return (x == p[x] ? x : p[x] = get(p[x]));
    }
    void unify(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
        }
        cmp--;
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
    dsu G;
    G.init(n);
    int cycle = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (G.get(x) != G.get(y))
            G.unify(x, y);
        else
            cycle = 1;
    }
    if (G.cmp == 1 && m == n - 1 && cycle == 0)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}