#include <iostream>
using namespace std;
int power(int n, int k)
{
    if (k == 0)
        return 1;

    int subprob = power(n, k / 2);
    if (k & 1) {
        return n * subprob * subprob;
    }
    return subprob * subprob;
}
int slow_power(int a, int n)
{
    if (n == 0) {
        return 1;
    }
    return a * slow_power(a, n - 1);
}
int main()
{
    cout << power(2, 3) << endl;
}