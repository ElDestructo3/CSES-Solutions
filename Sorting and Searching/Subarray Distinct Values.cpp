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
    vector<int>a(n);
    map<int,int> mp;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        
    }
    int l=0,r=0,unique=0,ans=0;
    for (l=0;l<n;l++) {
        while (r<n && (mp[a[r]]>=1 ||unique<k)) {
            mp[a[r]]++;
            
            if (mp[a[r]]==1) {
                //cout<<"hi"<<endl;
                unique++;
                //cout<<unique<<endl;
            }
            //cout<<r<<" "<<unique<<endl;
            r++;
        }
        //cout<<l<<" "<<r<<" "<<unique<<endl;
        ans+=r-l;
        mp[a[l]]--;
        if (!mp[a[l]]) {
            unique--;
        }
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
    long long t=1;
    //cin>>t;
  
    while (t--) {
        solve();
    }
    
    
}