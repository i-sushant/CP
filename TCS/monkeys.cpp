#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1);
        vector<int> aug(n, 0);
        int t = 0;
        while (true) {
            for (int i = 0; i < n; i++) {
                aug[ans[i] - 1] = a[i];
            }
            t++;
            if (aug == ans)
                break;
            ans = aug;
            fill(aug.begin(), aug.end(), 0);
        }
        cout << t << endl;
    }
}