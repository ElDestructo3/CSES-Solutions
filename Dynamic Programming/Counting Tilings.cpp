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
int dp[1001][1<<11];

void generate_next_masks(int current_mask, int i, int next_mask, int n, vector<int>& next_masks) {
    if(i == n + 1) {
        next_masks.push_back(next_mask);
        return;
    }
      
    if((current_mask & (1 << i)) != 0) {
        generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);
    }
      
    if(i != n) {
        if((current_mask & (1 << i)) == 0 && (current_mask & (1 << (i+1))) == 0) {
            generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);    
        } 
    }       
      
    if((current_mask & (1 << i)) == 0) {
        generate_next_masks(current_mask, i + 1, next_mask + (1 << i), n, next_masks);    
    }
          
}

int solve(int col, int mask, const int m, const int n) {
    if (col == m + 1) {
        if (mask == 0) {
            return 1;
        }
        return 0;
    }

    if (dp[col][mask] != -1) {
        return dp[col][mask];
    }

    int ans = 0;
    vector<int> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);

    for (int next_mask: next_masks) {
        ans  = (ans + solve(col + 1, next_mask, m, n)) % MOD;
    }

    return dp[col][mask] = ans;
}


void solve() {
    int n,m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    
    cout << solve(1, 0, m, n) << endl;
   
    
}
    
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    
    int t=1;
    //cin>>t;
    
    while (t--) {
        
        solve();
    }
    
} 

 
 
