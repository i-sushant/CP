#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;
ll pow2[200001];

void precompute()
{
    pow2[0] = 1;
    for (int i = 1; i < 200001; i++) {
        pow2[i] = (pow2[i - 1] * 2);
        pow2[i] %= MOD;
    }
}
void lazy_up(ll* tree, ll* lazy, int idx, int s, int e)
{
    if (lazy[idx] != -1) {
        if (lazy[idx] == 0)
            tree[idx] = 0;
        else {
            tree[idx] = pow2[e - s + 1] % MOD - 1 % MOD;
            tree[idx] %= MOD;
        }
        if (s != e) {
            lazy[2 * idx] = lazy[idx];
            lazy[2 * idx + 1] = lazy[idx];
        }
        lazy[idx] = -1;
    }
}
ll query(ll* tree, int s, int e, int l, int r, ll* lazy, int idx)
{
    lazy_up(tree, lazy, idx, s, e);
    if (r < s || l > e)
        return 0;
    if (s >= l && e <= r) {
        return tree[idx] % MOD;
    }
    int mid = (s + e) / 2;
    ll left = query(tree, s, mid, l, r, lazy, 2 * idx);
    ll right = query(tree, mid + 1, e, l, r, lazy, 2 * idx + 1);
    if (r <= mid)
        return left % MOD;
    return ((left % MOD * pow2[min(e, r) - mid] % MOD) % MOD + right % MOD) % MOD;
}
void update(ll* tree, int s, int e, int l, int r, ll* lazy, int val, int idx)
{
    lazy_up(tree, lazy, idx, s, e);
    if (r < s || l > e)
        return;
    if (s >= l && e <= r) {
        if (val == 0) {
            tree[idx] = 0;
        } else {
            tree[idx] = (pow2[e - s + 1] - 1) % MOD * 1 % MOD;
            tree[idx] %= MOD;
        }
        if (s != e) {
            lazy[2 * idx] = val;
            lazy[2 * idx + 1] = val;
        }
        return;
    }
    int mid = (s + e) / 2;
    update(tree, s, mid, l, r, lazy, val, 2 * idx);
    update(tree, mid + 1, e, l, r, lazy, val, 2 * idx + 1);
    tree[idx] = (tree[2 * idx] % MOD * pow2[e - mid] % MOD) % MOD + tree[2 * idx + 1] % MOD;
    tree[idx] %= MOD;
}
int main()
{
    precompute();
    int n, q;
    cin >> n >> q;
    ll tree[4 * n + 1] = { 0 };
    ll lazy[4 * n + 1] = { -1 };
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t < 2) {
            update(tree, 0, n - 1, l, r, lazy, t, 1);
        } else {
            cout << query(tree, 0, n - 1, l, r, lazy, 1) << endl;
        }
    }
}