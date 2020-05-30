#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        };
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int zero = 0;
            int ones = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] & (1 << i)) {
                    ones++;
                } else {
                    zero++;
                }
            }
            ans += (zero * ones);
        }
        cout << ((2 * ans) % 1000000007) << endl;
    }
    return 0;
}