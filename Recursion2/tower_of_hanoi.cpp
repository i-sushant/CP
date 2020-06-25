#include <bits/stdc++.h>
using namespace std;
void move(int n, char src, char helper, char dest)
{
    if (n == 0)
        return;
    move(n - 1, src, dest, helper);
    cout << "Shift " << src << " " << dest << endl;
    move(n - 1, helper, src, dest);
}
int main()
{
    move(3, 'A', 'B', 'C');
}