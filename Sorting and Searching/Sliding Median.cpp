#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
 
void solve() {
    int n,k;
    cin>>n>>k;
    ordered_set <pair<int,int>> s;
    vector<int> arr(n);
    for (int i=0;i<k-1;i++) {
      
        cin>>arr[i];
        s.insert({arr[i],i});
    }
    for (int i=0;i<n-k+1;i++) {
        
        cin>>arr[k-1+i];
        s.insert({arr[k-1+i],k-1+i});
        int ans=(*s.find_by_order((k-1)/2)).first;  
        cout<<ans<<" ";
        s.erase({arr[i],i});
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