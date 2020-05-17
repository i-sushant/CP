#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(a) / sizeof(int);
    int key = 16;
    bool present = binary_search(a, a + n, key);
    auto lit = lower_bound(a, a + n, key);
    if ((lit - a) == n) {
        cout << "Element not present" << endl;
    }
    int li = lit - a;
    auto uit = upper_bound(a, a + n, key);
    int ui = uit - a;
    cout << li << endl;
    cout << ui << endl;
    cout << ui - li << endl; //no of elements
    if (present) {
        cout << "Present";
    } else {
        cout << "Not present";
    }
}