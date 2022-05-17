#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
 
bool check(vector<int>arr, int mid, int k) {
    int num=1;
    int sum=0;
    int n=arr.size();
    for (int i=0;i<n;i++) {
        if (sum+arr[i]>mid) {
            num++;
            sum=arr[i];
        }
        else {
            sum+=arr[i];
        }
    }
    return num<=k;
    
}
 
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int low=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        low=max(low,a[i]);
    }
    int high=1e18;
    while (low<=high) {
        int mid = low + (high-low)/2;
        //cout<<mid<<" "<<check(a,mid,k)<<endl;
        if (check(a, mid, k)) {
            high=mid-1;
        }
        else {
            low=mid+1;
        }
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