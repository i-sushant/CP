#include <iostream>
#define INT_MAX 10000000
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = INT_MAX;
    int occ = 0;

    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            occ = 0;
            while (k % i == 0) {
                occ++;
                k /= i;
            }
            int cnt = 0;
            long long p = i;
            while (p <= n) {
                cnt += n / p;
                p = p * i;
            }
            ans = min(ans, cnt / occ);
        }
    }
    if (k > 1) {
        int cnt = 0;
        long long p = k;
        while (p <= n) {
            cnt += n / p;
            p *= k;
        }
        ans = min(ans, cnt);
    }
    if (ans == INT_MAX) {
        ans = 0;
    }
    cout << ans << endl;
}