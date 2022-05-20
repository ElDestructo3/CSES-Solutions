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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> dp (n, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '*') dp[i][j] = 0;
            else if (i > 0 && j > 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; dp[i][j] %= MOD;
            }
            else if (i > 0) dp[i][j] = dp[i - 1][j];
            else if (j > 0) dp[i][j] = dp[i][j - 1];
            else dp[i][j] = 1;
            

        }
        
    }
    cout << dp[n - 1][n - 1] << endl;
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