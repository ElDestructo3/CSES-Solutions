#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    multiset<int>s;
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        auto it = s.upper_bound(temp);
        if (it != s.end()) {
            s.erase(it);
        }
        s.insert(temp);
    }
    cout<<s.size()<<endl;
   
 
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
 