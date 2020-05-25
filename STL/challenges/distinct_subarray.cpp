#include <bits/stdc++.h>
using namespace std;

long long solve(int a[], int n)
{
    set<int> s;
    unordered_map<int, pair<int, int>> m;
    int i = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && s.find(a[j]) == s.end()) {
            s.insert(a[j]);
            j++;
        }
        m.insert(make_pair(i, make_pair(j, j - i)));
        s.erase(a[i]);
    }
    long long sum = 0;
    for (auto it : m) {
        int e = it.second.second;
        sum += (e * (e + 1)) / 2;
    }
    return sum % 1000000007;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(a, n) << endl;
}
