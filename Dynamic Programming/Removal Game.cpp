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
    vector<int> num(n);
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        prefix[i+1] = prefix[i] + num[i];
        
    }
    vector<vector<int>>dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = num[i];
    }
    for (int i = n-1; i>=0; i--) {
        for (int j = i+1; j<n; j++) {
            dp[i][j] = max(num[i] + prefix[j+1] - prefix[i+1] - dp[i+1][j], num[j] + prefix[j] - prefix[i] - dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;

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