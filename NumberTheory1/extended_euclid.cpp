#include <bits/stdc++.h>
using namespace std;
int x, y, GCD;
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
int main()
{
    extended(18, 30);
    cout << x << ", " << y << endl;
    return 0;
}