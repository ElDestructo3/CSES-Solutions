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
   
    
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = 1e9;
            int flag = a[i-1] == b[j-1] ? 0 : 1;
            dp[i][j] = min({dp[i-1][j-1] + flag, dp[i-1][j] + 1, dp[i][j-1] + 1});  
        }
    }
    
    cout << dp[n][m] << endl;

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