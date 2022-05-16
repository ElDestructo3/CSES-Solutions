#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    long long n;
    cin>>n;
    cout<<n;
    while (n!=1) {
        if (n%2) {
            n*=3;
            n++;
            cout<<" "<<n;
        }
        else {
            n/=2;
            cout<<" "<<n;
        }
    }
    
    
}
 
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long t;
    //cin>>t;
    t=1;
    while (t--) {
        solve();
    }
}