#include <iostream>
using namespace std;
void decr(int n)
{
    if (n == 0) {
        return;
    }
    cout << n << " ";
    decr(n - 1);
}
void incr(int n)
{
    if (n == 0) {
        return;
    }
    incr(n - 1);
    cout << n << " ";
}
int main()
{
    incr(5);
    cout << endl;
    decr(5);
}