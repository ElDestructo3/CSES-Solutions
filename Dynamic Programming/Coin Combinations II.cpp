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
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1; 
    for (int j = 0; j < n; j++) {
        for (int i = c[j]; i <= x; i++) {
            dp[i] += dp[i - c[j]];
            dp[i] %= MOD;
        }
    }
 
    cout << dp[x] << endl;
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