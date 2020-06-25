#include <bits/stdc++.h>
using namespace std;
string sp[10] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
void print(int n)
{
    if (n == 0) {
        return;
    }
    print(n / 10);
    cout << sp[(n % 10)] << " ";
}
int main()
{
    print(20485);
}