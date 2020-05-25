#include <iostream>
using namespace std;
int clearRangeItoj(int n, int i, int j)
{
    int mask1 = (-1 << (j + 1));
    int mask2 = ~(-1 << i);
    int mask3 = (1 << i) - 1; //use this or mask2
    int mask = mask1 | mask2;
    return n & mask;
}
int replace(int n, int m, int i, int j)
{
    int n_ = clearRangeItoj(n, i, j);
    int ans = n_ | (m << i);
    return ans;
}
int main()
{
    int n = 15;
    int i = 1, j = 3, m = 2;
    cout << replace(n, m, i, j) << endl;
}