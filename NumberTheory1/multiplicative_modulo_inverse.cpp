#include <bits/stdc++.h>
using namespace std;
int x, y, GCD;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void extended(int a, int b)
{
    if (b == 0) {
        x = 1;
        y = 0;
        GCD = a;
        return;
    }
    //recursive case
    extended(b, a % b);
    int cx = y;
    int cy = x - (a / b) * y;
    x = cx;
    y = cy;
}
int inverseMod(int a, int m)
{
    if (gcd(a, m) == 1) {
        extended(a, m);
    }
    return (x + m) % m;
}
int main()
{
    cout << inverseMod(6, 34) << endl;
    return 0;
}