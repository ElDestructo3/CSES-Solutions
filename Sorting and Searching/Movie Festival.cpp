#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> times(n);
    for (int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        times[i] = make_pair(b,a);
    }
    sort(times.begin(), times.end());
    int ans=0;
    int finish_time = 0;
    for (int i=0;i<n;i++) {
        if (times[i].second>=finish_time) {
            ans++;
            finish_time = times[i].first;
        }
        else {
            continue;
        }
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