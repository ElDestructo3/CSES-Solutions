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
    ordered_set<pair<int,int>> T;
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        T.insert({a[i], i});
    }
    
    while (q--) {
        char c;
        cin >> c;
        if (c == '!') {
            int x, y;
            cin >> x >> y;
            T.erase({a[x], x});
            a[x] = y;
            T.insert({a[x], x});
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << T.order_of_key({y,1e18}) - T.order_of_key({x-1, 1e18}) << endl;
        }
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