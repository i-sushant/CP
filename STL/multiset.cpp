#include <iostream>
#include <set>
using namespace std;
typedef multiset<int>::iterator It;
int main()
{
    int a[] = { 10, 20, 30, 20, 10, 40, 30, 30, 30, 30 };
    multiset<int> m(a, a + sizeof(a) / sizeof(int));
    m.erase(20);
    m.insert(80);
    for (int x : m) {
        cout << x << ", ";
    }
    cout << endl;
    cout << m.count(80) << endl;
    auto itr = m.find(30);
    cout << *itr << endl;
    pair<It, It> p = m.equal_range(30);
    for (auto it = p.first; it != p.second; it++) {
        cout << *it << ", ";
    }
    cout << endl;
    for (auto it = m.lower_bound(10); it != m.upper_bound(77); it++) {
        cout << *it << ",";
    }
}