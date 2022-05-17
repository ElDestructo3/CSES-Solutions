#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
    
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> prefix_sums(n+1);
    prefix_sums[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix_sums[i] = prefix_sums[i-1] + arr[i-1];
    }
    set<pair<int, int>> window;
    for (int i = a; i <= b; i++) {
        window.insert({prefix_sums[i], i});
    }
    int ans = LONG_LONG_MIN;
    for (int i = 1; i <= n - a + 1; i++) {
        ans = max(ans, window.rbegin()->first - prefix_sums[i-1]);
        window.erase({prefix_sums[i + a -1], i + a -1});
        if (i + b <= n) {
            window.insert({prefix_sums[i + b], i + b});
        }
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