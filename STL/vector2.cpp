#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> d { 1, 2, 3, 4, 5 };
    d.push_back(15);

    for (int x : d) {
        cout << x << ",";
    }
    cout << endl;
    d.pop_back();
    for (int x : d) {
        cout << x << ",";
    }
    cout << endl;

    d.insert(d.begin() + 3, 100);
    for (int x : d) {
        cout << x << ",";
    }
    cout << endl;
    d.insert(d.begin() + 3, 4, 100);
    for (int x : d) {
        cout << x << ",";
    }
    cout << endl;

    //erase

    d.erase(d.begin() + 3);
    d.erase(d.begin() + 2, d.begin() + 5);
    for (int x : d) {
        cout << x << ",";
    }
    cout << endl;
    cout << d.front() << endl;
    cout << d.back() << endl;
    d.clear();
    if (d.empty()) {
        cout << "Empty" << endl;
    }
    cout << d.size() << endl;

    int n;
    cin >> n;
    vector<int> v;
    // to avoid doubling we use reserve function
    v.reserve(1000);
    for (int i = 0; i < n; i++) {
        int no;
        cin >> no;
        v.push_back(no);
    }
}