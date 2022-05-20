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
   
    
}
    
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<vector<int>> dp(1e6 + 7, vector<int>(8,0));
    for (int i = 0; i < 8; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < 1e6 + 7; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == 0 || j == 2 || j == 3 || j == 4 || j == 5) {
                dp[i][j] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5]) % MOD;
            }

            else {
                dp[i][j] = (dp[i-1][2] + dp[i-1][6] + dp[i-1][7]) % MOD;
            }
        }
    }
    long long t=1;
    cin>>t;
    
    while (t--) {
        int n;
        cin >> n;
        cout<< (dp[n-1][2] + dp[n-1][6]) % MOD <<endl;
    }
    
    
    
}