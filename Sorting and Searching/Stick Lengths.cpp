#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    int minnum = INT_MAX, maxnum = INT_MIN;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        minnum = min(minnum, a[i]);
        maxnum = max(maxnum, a[i]);
    }
    sort(a.begin(), a.end());
    int median = n%2==0 ? (a[n/2]+a[n/2-1])/2 : a[n/2];
    int ans=0;
    for (int i=0;i<n;i++) {
        ans+=abs(a[i]-median);
    }
    cout<<ans<<endl;
   
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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