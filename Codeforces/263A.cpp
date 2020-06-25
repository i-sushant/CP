#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[5][5];
    int m;
    int n;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> A[i][j];
            if (A[i][j] == 1) {
                m = i;
                n = j;
            }
        }
    }
    int count = 0;
    while (A[2][2] != 1) {
        if (m < 2) {
            swap(A[m][n], A[m + 1][n]);
            m++;
        } else if (m > 2) {
            swap(A[m][n], A[m - 1][n]);
            m--;
        } else if (n < 2) {
            swap(A[m][n], A[m][n + 1]);
            n++;
        } else if (n > 2) {
            swap(A[m][n], A[m][n - 1]);
            n--;
        }
        count++;
    }
    cout << count << endl;
}