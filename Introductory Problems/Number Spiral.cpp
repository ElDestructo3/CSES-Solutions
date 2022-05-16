#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    
    long long x, y;
    cin >> x >> y;
    long long ans;
    long long temp = max(x,y);
    ans = temp*temp - temp + 1;
    ans += temp%2 ? (y - x) : (x - y);
    cout<<ans<<endl;
    
      
}
 
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long t;
    cin>>t;
    //t=1;
    while (t--) {
        solve();
    }
}