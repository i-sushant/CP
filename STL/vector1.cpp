#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //init
    vector<int> v;
    vector<int> b(5, 10); //five int with value 10
    vector<int> c(b.begin(), b.end());
    vector<int> d { 1, 2, 3, 4, 5 };

    //iterate over vector

    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << endl;
    }
    cout << endl;

    for (auto it = b.begin(); it != b.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;

    for (int x : b) {
        cout << x << ", ";
    }
    cout << endl;

    //accept elements from user

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int no;
        cin >> no;
        v.push_back(no);
    }
    for (int x : v) {
        cout << x << ", ";
    }
    cout << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << v.max_size() << endl;
}