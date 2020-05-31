#include <iostream>
using namespace std;
int mul(int n, int k)
{
    if (k == 0) {
        return 0;
    }
    int ans = n;
    return ans + mul(n, k - 1);
}
int main()
{
    cout << mul(5, 5) << endl;
}