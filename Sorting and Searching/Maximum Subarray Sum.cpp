#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int maxnum=INT_MIN,currnum=INT_MIN;
    for (int i=0;i<n;i++) {
        currnum = max(a[i], currnum+a[i]);
        maxnum = max(maxnum, currnum);
    }
    cout<<maxnum<<endl;
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