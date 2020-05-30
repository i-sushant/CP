#include <iostream>
using namespace std;
int rightMostSetBit(int n)
{
    int pos = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            pos = i;
        }
    }
    return pos;
}

int solve(int a, int b)
{
    int x = a ^ b;
    int count = 0;
    while (x) {
        count++;
        x = x >> 1;
    }
    return (1 << count) - 1;
}
int main()
{
    int l, r;
    cin >> l >> r;
    cout << solve(l, r) << endl;
}