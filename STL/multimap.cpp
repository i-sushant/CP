#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    multimap<int, string> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char ch;
        string s;
        cin >> ch >> s;
        m.insert(make_pair(ch, s));
    }
    auto it = m.begin();
    m.erase(it);
    auto it2 = m.lower_bound('b');
    auto it3 = m.upper_bound('d');
    for (auto it4 = it2; it4 != it3; it4++) {
        cout << it->first << " " << it->second << endl;
    }
    for (auto x : m) {
        cout << x.first << " " << x.second << endl;
    }
    auto f = m.find('c');
    if (f->second == "cat") {
        m.erase(f);
    }
}