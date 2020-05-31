#include <iostream>
using namespace std;
int search(int* a, int k, int l, int r)
{
    if (l > r) {
        return -1;
    }
    int mid = l + (r - l) / 2;
    int idx = -1;
    if (a[mid] == k)
        return mid;
    else if (a[mid] > k)
        idx = search(a, k, l, mid - 1);
    else
        idx = search(a, k, mid + 1, r);
    return idx;
}
int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(a) / sizeof(int);
    int k = 7;
    cout << search(a, k, 0, n - 1);
}