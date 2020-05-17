#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    //Init string
    string s0;

    string s1("Hello");
    string s2 = "Hello world";
    string s3(s2);
    string s4 = s3;
    char a[] = { 'a', 'b', 'c', '\0' };
    string s5(a);
    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;

    if (s0.empty()) {
        cout << "Empty" << endl;
    }

    //append
    s0.append("I love c++");
    cout << s0 << endl;
    s0 += " and python";
    cout << s0 << endl;

    //remove or erase
    cout << s0.length() << endl;
    s0.clear();
    cout << s0.length() << endl;

    s0 = "Apple";
    s1 = "Mango";

    cout << s1.compare(s0) << endl; //returns an integer 0 , > 0, < 0

    //overloaded operators

    if (s1 > s0) {
        cout << "mango > apple" << endl;
    }

    //find substrings
    string s = "I want honey and mango";
    int idx = s.find("mango");
    cout << idx << endl;

    //remove a word from the string

    string word = "mango";
    s.erase(idx, word.length() + 1);
    cout << s << endl;

    //iterate over all the character of the string

    for (int i = 0; i < s1.length(); i++) {
        cout << s1[i] << ":";
    }
    cout << endl;
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << (*it) << ",";
    }
    cout << endl;
    for (auto x : s1) {
        cout << x;
    }
}