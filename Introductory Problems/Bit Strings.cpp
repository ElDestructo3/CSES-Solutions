#include <bits/stdc++.h>
 
using namespace std;
 
 
void solve() {
    
    long long n;
    cin>>n;
    int MOD = 1e9 + 7;
    long long ans = 1, x = 2;
    for (int i = 0; i<n; i++) {
        ans = (ans * x) % MOD;
        
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