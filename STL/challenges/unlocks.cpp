#include <bits/stdc++.h>
using namespace std;

int* solve(int a[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        m.insert(make_pair(a[i], i));
    }
    int temp = n;
    int i = 0;
    while (k > 0 && i < n) {
        if (a[i] != temp) {

            int f = m[a[i]];
            int s = m[temp];

            int t = a[f];
            a[i] = a[s];
            a[s] = t;

            m[a[i]] = f;
            m[a[s]] = s;

            k--;
        }
        temp--;
        i++;
    }
    return a;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int* res = solve(a, n, k);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}