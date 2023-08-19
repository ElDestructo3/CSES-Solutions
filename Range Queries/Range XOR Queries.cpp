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
vector<pair<int,int>> dir = {{1,0}, {0,1}, {0,-1}, {-1,0}};
int K = 25;
int MAXN = 2e5 + 5;
 
void solve(int t) {
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &v: a) {
        cin >> v;
    }
    vector<int> prefixXOR(n + 1);
    prefixXOR[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefixXOR[i] = prefixXOR[i - 1] ^ a[i - 1];
    }
    while (q--) {
        int left, right;
        cin >> left >> right;
        cout << (prefixXOR[right] ^ prefixXOR[left - 1]) << endl;
    }
    
    
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
    
    for (int i =0; i<t;i++){
        
        solve(i);
    }
    
    
    
}  