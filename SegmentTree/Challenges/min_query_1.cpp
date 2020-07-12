#include <bits/stdc++.h>
using namespace std;
void build(int* a, int s, int e, int* tree, int idx)
{
    if (s == e) {
        tree[idx] = a[s];
        return;
    }
    int mid = (s + e) / 2;
    build(a, s, mid, tree, 2 * idx);
    build(a, mid + 1, e, tree, 2 * idx + 1);
    tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
    return;
}
int query(int* tree, int s, int e, int l, int r, int idx)
{
    if (s >= l && e <= r) {
        return tree[idx];
    }
    if (r < s || l > e) {
        return INT_MAX;
    }
    int mid = (s + e) / 2;
    int left = query(tree, s, mid, l, r, 2 * idx);
    int right = query(tree, mid + 1, e, l, r, 2 * idx + 1);
    return min(left, right);
}
void update(int* tree, int s, int e, int x, int y, int idx)
{
    if (x < s || x > e)
        return;
    if (s == e) {
        tree[idx] = y;
        return;
    }
    int mid = (s + e) / 2;
    update(tree, s, mid, x, y, 2 * idx);
    update(tree, mid + 1, e, x, y, 2 * idx + 1);
    tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
}
int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tSize = 4 * n + 1;
    int* tree = new int[tSize];
    build(a, 0, n - 1, tree, 1);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            int ans = query(tree, 0, n - 1, l - 1, r - 1, 1);
            cout << ans << endl;
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            update(tree, 0, n - 1, x - 1, y, 1);
        }
    }
}