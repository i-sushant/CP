#include <bits/stdc++.h>
using namespace std;
void buildTree(int* a, int s, int e, vector<vector<int>>& tree, int idx)
{
    if (s == e) {
        vector<int> v;
        v.push_back(a[s]);
        tree[idx] = v;
        return;
    }
    int mid = (s + e) / 2;
    buildTree(a, s, mid, tree, 2 * idx);
    buildTree(a, mid + 1, e, tree, 2 * idx + 1);
    merge(tree[2 * idx].begin(), tree[2 * idx].end(), tree[2 * idx + 1].begin(), tree[2 * idx + 1].end(), back_inserter(tree[idx]));
}
int maxQ(vector<vector<int>>& tree, int s, int e, int l, int r, int k, int idx)
{
    if (r < s || l > e)
        return 0;
    if (s >= l && e <= r) {
        auto pos = lower_bound(begin(tree[idx]), end(tree[idx]), k);
        return tree[idx].size() - (pos - tree[idx].begin());
    }
    int mid = (s + e) / 2;
    int left = maxQ(tree, s, mid, l, min(r, mid), k, 2 * idx);
    int right = maxQ(tree, mid + 1, e, max(mid + 1, l), r, k, 2 * idx + 1);
    return left + right;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int treeSize = 4 * n + 1;
    vector<vector<int>> tree(treeSize);
    buildTree(a, 0, n - 1, tree, 1);
    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int ans = maxQ(tree, 0, n - 1, l - 1, r - 1, k, 1);
        cout << ans << endl;
    }
}