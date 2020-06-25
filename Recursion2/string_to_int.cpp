#include <bits/stdc++.h>
using namespace std;
int strToInt(char* num, int n)
{
    if (n == 0)
        return 0;
    int digit = num[n - 1] - '0';
    int smallAns = strToInt(num, n - 1);
    return smallAns * 10 + digit;
}
int main()
{
    char a[] = "1234";
    int len = strlen(a);
    int st = strToInt(a, len);
    cout << st;
}