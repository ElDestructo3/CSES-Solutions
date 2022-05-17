#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;
 
#define int long long
 
void solve() {
    int n,k;
    cin>>n>>k;
 
    for (int i = 0; i < n; i++) {
        T.insert(i+1);
    }
    int idx = k;
    while (T.size()){
        idx %= T.size();
        int x = *T.find_by_order(idx);
        T.erase(x);
        printf("%lld%c", x, (" \n")[T.size() == 0]);
        idx += k;
 
    }
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
 