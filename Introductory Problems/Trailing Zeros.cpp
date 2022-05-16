#include <bits/stdc++.h>
 
using namespace std;
 
 
void solve() {
    
    long long ans = 0;
    long long n;
    cin>>n;
    long long x = 5;
    while (n>=x) {
        ans += n/x;
        x *= 5;
    }
    cout<<ans<<endl;
      
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