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

int dp[20][10][2][2];

int solve(string& number, int n, int x, bool leadingZeros, bool tightBound) {
    if (n == 0) return 1;

    if (x != -1 && dp[n][x][(int)leadingZeros][(int)tightBound] != -1) {
        return dp[n][x][(int)leadingZeros][(int)tightBound];
    }

    int lowerBound = 0;
    int upperBound = tightBound ? (number[number.length() - n] - '0'): 9;

    int ans = 0;
    for (int digit = lowerBound; digit <= upperBound; digit++) {
        if (digit == x && !leadingZeros) continue;
        ans += solve(number, n - 1, digit, (leadingZeros & digit == 0), tightBound & (digit == upperBound));
    }

    return dp[n][x][(int)leadingZeros][(int)tightBound] = ans;
}

void solve() {
    int a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    string A = to_string(a-1);
    string B = to_string(b);
    int ans = solve(B, B.length(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    cout << ans - solve(A, A.length(), -1, 1, 1);
   
    
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

 
 
