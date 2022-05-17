#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
 
bool check(int time, int products, vector<int> arr) {
    int num=0;
    for (int i=0;i<arr.size();i++) {
        num+=time/arr[i];
        if (num>=products) return true;
    }
    
    return false;
}
 
void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    map<int,int>mp;
    mp[0]=1;
    
    int left=0, right=0, sum=0,ans=0;
    for (right=0;right<n;right++) {
        cin>>arr[right];
        sum+=arr[right];
        
        ans+=mp[sum-x];
        mp[sum]++;
        
        
 
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