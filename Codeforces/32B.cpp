#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string ans = "";
    int i = 0;
    for (; i < s.length() - 1; i++) {
        if (s[i] == '-' && s[i + 1] == '.') {
            ans += "1";
            i++;
        } else if (s[i] == '-' && s[i + 1] == '-') {
            ans += "2";
            i++;
        } else if (s[i] == '.')
            ans += "0";
    }
    if (s[i] == '.')
        ans += "0";
    cout << ans << endl;
}