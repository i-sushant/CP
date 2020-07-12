#include <bits/stdc++.h>
using namespace std;
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
    //complete overlap
    if (s >= qs and e <= qe)
        return tree[idx];
    if (qe < s || qs > e)
        return INT_MAX;
    //Partial overlap
    int mid = (s + e) / 2;
    int left = query(tree, s, mid, qs, qe, 2 * idx);
    int right = query(tree, mid + 1, e, qs, qe, 2 * idx + 1);
    return min(left, right);
}
void rangeUpdate(int* tree,  int s, int e, int l, int r, int val, int idx)
{
    //out of bound
    if (l > e || r < s)
        return;
    //leaf node
    if (s == e) {
        tree[idx] += val;
        return;
    }
    int mid = (s + e) / 2;
    rangeUpdate(tree, s, mid, l, r, val, 2 * idx);
    rangeUpdate(tree, mid + 1, e, l, r, val, 2 * idx + 1);
    tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
    return;
}
void pointUpdate(int* tree, int s, int e, int i, int val, int idx)
{
    if (i < s || i > e)
        return;
    if (s == e) {
        tree[idx] += val;
        return;
    }
    int mid = (s + e) / 2;
    pointUpdate(tree, s, mid, i, val, 2 * idx);
    pointUpdate(tree, mid + 1, e, i, val, 2 * idx + 1);
    tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
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

    pointUpdate(tree, 0, n - 1, 3, 10, 1);
    rangeUpdate(tree, 0, n - 1, 0, 5, 3, 1);
    for (int i = 1; i <= 13; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    int ans = query(tree, 0, n - 1, 2, 4, 1);
    cout << ans << endl;
}