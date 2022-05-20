#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
const int MOD = 1e9 + 7;

void solve() {
   
    int n;
    cin >> n;
    int sum = n*(n+1);
    sum/=2;
    if (sum%2 !=0) {
        cout<<0<<endl;
        return;
    }
    sum/=2;
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        for (int j = sum; j >= i; j--) {
            dp[j] = (dp[j] +  dp[j-i]) % MOD;
        }
    }
    cout<<dp[sum]<<endl;

    

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