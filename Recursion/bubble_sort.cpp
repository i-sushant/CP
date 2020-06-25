#include <iostream>
using namespace std;
void bubble_sort(int a[], int n)
{
    //base case
    if (n == 1) {
        return;
    }
    //after you have moved the largest element in the current part to the end of the array by pairwise swapping
    for (int j = 0; j < n - 1; j++) {
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
        }
    }
    //sort the first n-1 elements
    bubble_sort(a, n - 1);
}
void bubble_sort_recursive(int a[], int j, int n)
{
    if (n == 1) {
        return;
    }
    if (j == n - 1) {
        //single pass of the current array
        // j has reached the end so you have to return back to the 1nd index now , if return is not used then recursion will proceed infinetely
        return bubble_sort_recursive(a, 0, n - 1);
    }
    if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
    }
    bubble_sort_recursive(a, j + 1, n);
    return;
}
int main()
{
    int a[] = { 5, 4, 3, 2, 1 };
    // bubble_sort(a, 5);
    bubble_sort_recursive(a, 0, 5);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
}