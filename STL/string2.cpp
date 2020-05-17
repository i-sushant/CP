#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
bool compareFn(string a, string b)
{
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() > b.length();
}
int main()
{
    int n;
    cin >> n;
    cin.get();
    string s[100];

    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }
    sort(s, s + n);
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    sort(s, s + n, compareFn);
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
}