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
    sort(a.begin(), a.end());
    int num=1;
    for (int i=0;i<n && a[i]<=num;i++) {
        num+=a[i];
    }
    cout<<num<<endl;
   
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