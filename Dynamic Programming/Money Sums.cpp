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
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
    }
    vector<bool> dp(sum + 1, 0);
    dp[0] = true;
    for(int i = 0; i < n; i++) {
        for (int j = sum; j >= num[i]; j--) {
            dp[j] = dp[j] || dp[j - num[i]];
        }
    }
    int count = 0;
    for (int i = sum; i > 0; i--) {
        if (dp[i]) {
            count++;
        }
    }
    cout<<count<<endl;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            cout << i << " ";
        }
    }
    cout<<endl;
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