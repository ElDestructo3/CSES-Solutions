#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    int n;
    cin>>n;
    map<int,int>mp;
    int ans=0, curr=0;
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        
        if (mp.count(temp)) {
            ans= max(ans, i-curr);
            curr=max(mp[temp]+1,curr);
            //cout<<ans<<endl;
        }
        mp[temp]=i;
        
    }
    ans=max(ans,n-curr);
    cout<<ans<<endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long t=1;
    //cin>>t;
  
    while (t--) {
        solve();
    }
    
    
}