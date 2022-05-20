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
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    pair<int, int> best[1 << n];
    best[0] = {1, 0};
    for (int s = 1; s < (1 << n); s++) {
        best[s] = {n + 1, 0};
        for (int p = 0; p < n; p++) {
            if (s & (1 << p)) {
                pair<int,int> option = best[s ^ (1 << p)];
                if (option.second + weights[p] <= x) {
                    option.second += weights[p];
                }
                else {
                    option.first++; 
                    option.second = weights[p];
                }
                best[s] = min(best[s], option);
            }
           
        }
    }
    cout << best[(1 << n) - 1].first << endl;
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

 
 
