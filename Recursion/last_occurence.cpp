#include <iostream>
using namespace std;
int lastOcc(int* a, int n, int k)
{
    if (n == 0) {
        return -1;
    }
    int i = lastOcc(a + 1, n - 1, k);
    if (i == -1) {
        if (a[0] == k) {
            return 0;
        } else {
            return -1;
        }
    }
    //otherwise if i returned by subproblem is not -1
    return i + 1;
}

int main()
{
    int a[] = { 1, 3, 10, 4, 7, 5, 3, 11 };
    int n = sizeof(a) / sizeof(int);
    cout << lastOcc(a, n, 3);
}