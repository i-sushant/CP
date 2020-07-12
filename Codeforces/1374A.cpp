#include <iostream>
#define ll long long
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--) {
        ll x, y, n;
        cin >> x >> y >> n;
        ll ans = n - (n % x) + y;
        if (ans <= n)
            cout << ans;
        else
            cout << ans - x;
        cout << endl;
    }
}