#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll freq[1000005],a[1000005];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 0; i<n;i++) {
            cin >> a[i];
            sum += a[i];
            sum = (sum + n) % n;
            freq[sum]++;
        }
        if(freq[0] >= 1) {
            return 0;
        } else {
            
        }

        
    }
}