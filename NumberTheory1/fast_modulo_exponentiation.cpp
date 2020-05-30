#include <iostream>
#define ll long long

using namespace std;
int fastModExp(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}
int main()
{
    cout << fastModExp(3, 5, 100);
}