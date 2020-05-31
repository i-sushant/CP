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
int main()
{
    cout << power(2, 3) << endl;
}