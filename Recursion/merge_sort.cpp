#include <iostream>
using namespace std;

void merge(int* a, int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int k = left;
    int b[left + right + 1];
    while (i <= mid - 1 && j <= right) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid - 1) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= right) {
        b[k] = a[j];
        j++;
        k++;
    }
    for (i = left; i <= right; i++) {
        a[i] = b[i];
    }
}
void merge_sort(int* a, int left, int right)
{
    if (right <= left)
        return;
    int mid = left + (right - left) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, mid + 1, right);
}
int main()
{
    int a[] = { 5, 3, 2, 8, 5, 8, 9, 1 };
    int n = sizeof(a) / sizeof(int);

    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}