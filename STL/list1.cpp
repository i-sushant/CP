#include <iostream>
#include <list>

using namespace std;

int main()
{
    //list is doubly linked list

    list<int> l;
    list<int> l1 { 1, 2, 3, 4, 5, 6, 7 };
    list<string> l2 { "apple", "banana", "mango", "guava" };
    l2.push_back("pineapple");

    for (auto x : l2) {
        cout << x << "->";
    }
    cout << endl;
    l2.sort();
    for (auto x : l2) {
        cout << x << "->";
    }
    cout << endl;
    l2.reverse();
    for (auto x : l2) {
        cout << x << "->";
    }
    l2.pop_front();
    cout << endl;
    cout << l2.front() << endl;

    for (auto it = l2.begin(); it != l2.end(); it++) {
        cout << *it << "->";
    }
    cout << endl;
    l2.push_back("Orange");
    l2.push_back("Lemon");
    l2.push_back("guava");
    string f;
    cin >> f;
    l2.remove(f);
    for (auto it = l2.begin(); it != l2.end(); it++) {
        cout << *it << "->";
    }

    //erase one or more element
    auto it = l2.begin();
    it++;
    l2.erase(it);
    cout << endl;
    for (auto it = l2.begin(); it != l2.end(); it++) {
        cout << *it << "->";
    }

    //insert in the list

    it = l2.begin();
    it++;
    l2.insert(it, "Fruitjuice");
    cout << endl;
    for (auto it = l2.begin(); it != l2.end(); it++) {
        cout << *it << "->";
    }
}