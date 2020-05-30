#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        double ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += n / (i * 1.0);
        }
        cout << fixed << setprecision(6) << ans << endl;
        return 0;
    }
}