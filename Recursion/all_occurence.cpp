#include <bits/stdc++.h>
using namespace std;
void allOcc(int* a, int n, int i, int k)
{
    if (i == n) {
        return;
    }
    if (a[i] == k)
        cout << i << ", ";
    allOcc(a, n, i + 1, k);
}
int storeOcc(int* a, int i, int n, int k, int* out, int j)
{
    if (i == n)
        return j;
    if (a[i] == k) {
        out[j] = i;
        //increament j to accomodate more elements
        return storeOcc(a, i + 1, n, k, out, j + 1);
    }
    //j remains unchanged
    return storeOcc(a, i + 1, n, k, out, j);
}
int main()
{
    int a[] = { 1, 3, 10, 4, 7, 5, 3, 11 };
    int n = sizeof(a) / sizeof(int);
    allOcc(a, n, 0, 3);
    cout << endl;
    int output[100];
    int cnt = storeOcc(a, 0, n, 3, output, 0);
    cout << cnt << endl;
    for (int k = 0; k < cnt; k++) {
        cout << output[k] << " ";
    }
}