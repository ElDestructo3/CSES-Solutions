#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> times(2*n);
    int temp1,temp2;
    for (int i=0;i<n;i++) {
        cin>>temp1>>temp2;
        times[2*i] = make_pair(temp1,1);
        times[2*i+1] = make_pair(temp2,-1);
    }
    sort(times.begin(),times.end());
    int ans = 0, cur=0;
    for (int i=0;i<2*n;i++) {
        cur+=times[i].second;
        ans=max(ans,cur);
    }
    cout<<ans<<endl;
    
   
}
 
signed main() {
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