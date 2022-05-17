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
    int n, products;
    cin>>n>>products;
    vector<int>arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int low=0, high=1e18;
    while (low<=high) {
        int     mid = low + (high-low)/2;
        if (check(mid,products, arr)) high = mid-1;
        else low=mid+1;
    }
    cout<<low<<endl;
 
    
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