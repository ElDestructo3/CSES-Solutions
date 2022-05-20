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
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        
        while (num) {
            dp[i] =  min(dp[i - num%10], dp[i]);
            num /= 10;
        }
        dp[i]++;
    }
    cout << dp[n] << endl;
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