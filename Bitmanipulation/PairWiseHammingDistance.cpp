#include <iostream>
#define mod 1000000007
using namespace std;
int solve(int a[], int n)
{
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] & (1 << i)) {
                count++;
            }
        }
        ans += 2 * count * (n - count);
        ans %= mod;
    }
    return ans;
}
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
        }
        cout << solve(a, n) << endl;
    }
}