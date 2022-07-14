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
vector<vector<int>>adjacencyList(2e5 + 5);
vector<vector<int>>reverseadjacencyList(2e5 + 5);
vector<int> id(2e5 + 5);
vector<int> order;
 
 
 
void solve(int t) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> pre(n+1);
    pre[0] = 0;
    for (int i = 0; i < n; ++i) {
        pre[i+1] = pre[i] + a[i];
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a-1] << endl;
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