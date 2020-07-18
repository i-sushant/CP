#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string brides, grooms;
    cin >> brides >> grooms;
    queue<char> b;
    queue<char> g;
    for (int i = 0; i < n; i++) {
        b.push(brides[i]);
        g.push(grooms[i]);
    }
    size_t reject = 0;

    while (reject != g.size()) {
        if (b.front() == g.front()) {
            b.pop();
            g.pop();
            reject = 0;
        } else {
            g.push(g.front());
            g.pop();
            reject++;
        }
    }
    cout << g.size() << endl;
}