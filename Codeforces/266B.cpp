#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    char a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (t--) {
        for (int i = 1; i < n; i++) {
            if (a[i] == 'G' && a[i - 1] == 'B') {
                swap(a[i - 1], a[i]);
                i++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
}