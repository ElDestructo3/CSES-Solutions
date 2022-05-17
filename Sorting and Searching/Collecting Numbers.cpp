#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<int>b(n+1);
    
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        b[a[i]]=i;
        
    }
    vector<int>c(n+1);
    int count=1;
  
    for (int i=2;i<=n;i++) {
        if (b[i]<b[i-1]) {
            count++;
        }
        else {
            
        }
    }
       
    cout<<count<<endl;
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