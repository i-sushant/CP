#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        string res = "";
        for (int i = 0; i < a.length(); i++) {
            int ans = a[i] ^ b[i];
            res += to_string(ans);
        }
        cout << res << endl;
    }
}