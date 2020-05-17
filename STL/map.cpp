#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    //insert
    map<string, int> m;
    m.insert(make_pair("Mango", 100));

    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);

    m["banana"] = 20;

    //search

    string fruit;
    cin >> fruit;
    //update
    m[fruit] += 20;
    auto it = m.find(fruit);
    if (it != m.end()) {
        cout << fruit << endl;
    } else {
        cout << "fruit absent" << endl;
    }

    if (m.count(fruit)) {
        cout << "Price : " << m[fruit] << endl;
    }

    //erase
    m.erase(fruit);
    m["lichi"] = 60;
    m["pineapple"] = 50;
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    for (auto x : m) {
        cout << x.first << " " << x.second << endl;
    }
}