#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int key;
    int a[] = { 1, 3, 4, 6, 6, 9, 4, 2 };
    cin >> key;
    int n = sizeof(a) / sizeof(int);
    auto it = find(a, a + n, key);
    int idx = it - a;

    if (idx == n) {
        cout << "Key not found";
    } else {
        cout << idx;
    }
}