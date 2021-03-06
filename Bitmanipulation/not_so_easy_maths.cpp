#include <iostream>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    ll primes[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
    while (t--) {
        ll n;
        cin >> n;

        ll subsets = (1 << 8) - 1;
        ll ans = 0;
        for (ll i = 1; i <= subsets; i++) {
            ll denom = 1ll;
            ll setBits = __builtin_popcount(i);

            for (ll j = 0; j <= 7; j++) {
                if (i & (1 << j)) {
                    denom = denom * primes[j];
                }
            }

            if (setBits & 1) { //if setBits is even number then least significant bit will always be 0 , so this consition will fail
                ans += n / denom;
            } else {
                ans -= n / denom;
            }
        }
        cout << ans << endl;
    }
}