#include <bits/stdc++.h>
using namespace std;

void replace(char* s, int n)
{
    if (s[n] == '\0' or s[n + 1] == '\0')
        return;

    if (s[n] == 'p' and s[n + 1] == 'i') {
        int m = n + 2;
        while (s[m] != '\0') {
            m++;
        }
        while (m >= n + 2) {
            s[m + 2] = s[m];
            m--;
        }
        s[n] = '3';
        s[n + 1] = '.';
        s[n + 2] = '1';
        s[n + 3] = '4';
        replace(s, n + 4);
    } else {
        replace(s, n + 1);
    }
    return;
}

int main()
{
    char s[1000];
    cin >> s;
    replace(s, 0);
    int i = 0;
    while (s[i] != '\0') {
        cout << s[i] << "";
        i++;
    }
}