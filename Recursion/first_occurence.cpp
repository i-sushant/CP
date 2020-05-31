#include <iostream>
using namespace std;
int firstOcc(int* a, int n, int k)
{
    if (n == 0) {
        return -1;
    }
    if (a[0] == k) {
        return 0;
    }
    int i = firstOcc(a + 1, n - 1, k);
    if (i == -1) {
        return -1;
    }
    return i + 1;
}
int linearsearch(int* a, int i, int n, int key)
{
    if (i == n)
        return -1;
    int i = linearsearch(a, i + 1, n);
    if (a[i] == key) {
        return i;
    }
    return linearsearch(a, i + 1, n, key);
}
int main()
{
    int a[] = { 1, 2, 10, 4, 7, 5, 3, 11 };
    int n = sizeof(a) / sizeof(int);
    cout << firstOcc(a, n, 10);
}