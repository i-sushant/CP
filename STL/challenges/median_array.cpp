#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int b[], int n)
{
    int c[2 * n];
    int i, j, k;
    i = j = k = 0;
    for (; i < 2 * n; i++) {
        if (a[j] <= b[k]) {
            c[i] = a[j];
            j++;
        } else {
            c[i] = b[k];
            k++;
        }
    }
    int idx = ((2 * n) / 2) - 1;
    return idx;
}
int solveUnequal(int a[], int n, int b[], int m)
{
    int size = n + m;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        c.push_back(a[i]);
    }
    for (int i = 0; i < m; i++) {
        c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    int median;
    int e = size / 2;
    if ((size % 2) == 0) {
        median = (c[e - 1] + c[e + 1]) / 2;
    } else {
        median = c[e] / 2;
    }
    return median;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        cout << solveUnequal(a, n, b, m) << endl;
    }
}