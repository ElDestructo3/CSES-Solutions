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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    vector<vector<int>>dp (n, vector<int>(m+1,0));
    if (arr[0] != 0) {
        dp[0][arr[0]] = 1;
    }
    else {
        for (int i = 0; i < m; i++) {
            dp[0][i+1] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] != 0) {
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i]]) % MOD;

            if (arr[i] - 1 >= 1) {
                dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] - 1]) % MOD;     
            }
            if (arr[i] + 1 <= m) {
                dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] + 1]) % MOD;
            }
        }
        else {
            for (int j = 1; j <=    m; j++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;

                if (j - 1 >= 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
                
                if (j + 1 <= m) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
                
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n-1][i]) % MOD;
    }
    cout << ans << endl;
    
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