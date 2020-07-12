#include <bits/stdc++.h>
using namespace std;
int lazy[100000] = { 0 };
void buildTree(int* a, int s, int e, int* tree, int idx)
{
    if (s == e) {
        tree[idx] = a[s];
        return;
    }
    int mid = (s + e) / 2;
    buildTree(a, s, mid, tree, 2 * idx);
    buildTree(a, mid + 1, e, tree, 2 * idx + 1);
    tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
    return;
}
int query(int* tree, int s, int e, int qs, int qe, int idx)
{
    //resolve the lazy value
    if (lazy[idx] != 0) {
        tree[idx] += lazy[idx];
        if (s != e) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    //no overlap
    if (qe < s || qs > e)
        return INT_MAX;
    //complete overlap
    if (s >= qs and e <= qe)
        return tree[idx];

    //Partial overlap
    int mid = (s + e) / 2;
    int left = query(tree, s, mid, qs, qe, 2 * idx);
    int right = query(tree, mid + 1, e, qs, qe, 2 * idx + 1);
    return min(left, right);
}
void updateLazy(int* tree, int s, int e, int l, int r, int val, int idx)
{
    if (lazy[idx] != 0) {
        tree[idx] += lazy[idx];
        if (s != e) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (r < s or l > e) {
        return;
    }
    //complete overlap
    if (s >= l && e <= r) {
        tree[idx] += val;
        //create a new lazy value for children node;
        if (s != e) {
            lazy[2 * idx] += val;
            lazy[2 * idx + 1] += val;
        }
        return;
    }
    int mid = (s + e) / 2;
    updateLazy(tree, s, mid, l, r, val, 2 * idx);
    updateLazy(tree, mid + 1, e, l, r, val, 2 * idx + 1);
    tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
    return;
}
int getSum(int* tree, int s, int e, int l, int r, int val, int idx)
{
    if (lazy[idx] != 0) {
        tree[idx] += lazy[idx] * (r - l + 1) * val;
        if (s != e) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    //no overlap
    if (r < s || l > e)
        return 0;
    //complete overlap
    else if (s >= l and e <= r)
        return tree[idx];
    int mid = (s + e) / 2;
    int left = getSum(tree, s, mid, l, r, val, idx);
    int right = getSum(tree, mid + 1, e, l, r, val, idx);
    return left + right;
}
int main()
{
    int a[] = { 1, 3, 2, -5, 6, 4 };
    int n = sizeof(a) / sizeof(int);
    int treeSize = 4 * n + 1;
    int* tree = new int[treeSize];
    buildTree(a, 0, n - 1, tree, 1);
    for (int i = 1; i <= 13; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    updateLazy(tree, 0, n - 1, 2, 4, 10, 1);
    for (int i = 1; i <= 13; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    int ans = query(tree, 0, n - 1, 2, 4, 1);
    cout << ans << endl;
}