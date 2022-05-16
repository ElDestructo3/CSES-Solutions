#include <bits/stdc++.h>
 
using namespace std;
 
long long f(long long n) {
    long long ans = n;
    ans*=n;
    ans*=n+1;
    ans*=n-1;
    ans/=2;
    ans-= 4*(n-1)*(n-2);
    return ans;
}
 
void solve() {
    
    long long n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cout<<f(i)<<endl;
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