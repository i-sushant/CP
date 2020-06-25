#include <bits/stdc++.h>
using namespace std;
long long c(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);

            p /= m;
            k /= m;
            n--;
            r--;
        }
    } else {
        p = 1;
    }
    return p;
}
int f(int n)
{
    // if (n == 0)
    //     return 1;
    if (n <= 1)
        return 1;
    if (n == 2)
        return 2;
    return f(n - 1) + (c(n - 1, 1) * f(n - 2));
}
int main()
{
    cout << f(5) << endl;
}