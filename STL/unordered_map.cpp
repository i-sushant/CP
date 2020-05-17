#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, string> m;
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
    for (auto x : m) {
        cout << x.first << " " << x.second << endl;
    }
    auto f = m.find('c');
    if (f->second == "cat") {
        m.erase(f);
    }
}