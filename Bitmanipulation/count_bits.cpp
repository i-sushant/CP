#include <iostream>
using namespace std;

int count(int n)
{
    int ans = 0;
    while (n > 0) {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}
int countBitFast(int n)
{
    int ans = 0;
    while (n > 0) {
        ans += (n & 1);
        n = n >> 1;
    }
    return ans;
}
int main()
{
    int n = 5;
    cout << count(n) << endl;
    cout << countBitFast(n) << endl;
    cout << __builtin_popcount(n) << endl;
}