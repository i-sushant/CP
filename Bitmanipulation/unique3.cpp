#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, no;
    cin >> n;
    int count[64] = { 0 };
    for (int i = 0; i < n; i++) {
        cin >> no;
        //update count array by extracting bits
        int j = 0;
        while (no > 0) {
            int last_bit = (no & 1);
            count[j] += last_bit;
            j++;
            no = no >> 1;
        }
    }
    //iterate over the array ans reduce everything by mod 3
    // and form the array by converting 0s and 1s into a number
    int p = 1;
    int ans = 0;
    for (int i = 0; i < 64; i++) {
        count[i] %= 3;
        ans += (count[i] * p);
        p = p << 1;
    }
    cout << ans << endl;
}