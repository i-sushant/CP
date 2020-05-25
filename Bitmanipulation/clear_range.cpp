#include <iostream>
using namespace std;
int clearLastBits(int n, int i)
{
    int mask = (-1 << i);
    return n & mask;
}
int clearRangeItoj(int n, int i, int j)
{
    int mask1 = (-1 << (j + 1));
    int mask2 = ~(-1 << i);
    int mask3 = (1 << i) - 1; //use this or mask2
    int mask = mask1 | mask2;
    return n & mask;
}
int main()
{
    int n = 31;
    int i = 1;
    int j = 3;
    cout << clearLastBits(n, i) << endl;
    cout << clearRangeItoj(n, i, j);
}