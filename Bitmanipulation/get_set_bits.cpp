#include <iostream>
using namespace std;
int oddornot(int n)
{
    return (n & 1);
}
int findithbit(int n, int i)
{
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}
int setBit(int n, int i)
{
    int mask = (1 << i);
    return (n | mask);
}
void clearBit(int& n, int i)
{
    int mask = ~(1 << i);
    n = n & mask;
}
void updateBit(int& n, int i, int v)
{
    int mask = ~(v << i);
    int cleared_n = n & mask;
    n = cleared_n | (v << i);
}
int main()
{
    int n = 5;
    int i = 2;
    cout << oddornot(n) << endl;
    cout << findithbit(n, i) << endl;
    cout << setBit(n, i) << endl;
    clearBit(n, i);
    cout << n << endl;
    updateBit(n, 4, 1);
    cout << n << endl;
}