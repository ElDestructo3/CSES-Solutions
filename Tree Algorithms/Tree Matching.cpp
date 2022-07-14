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
int MAXN = 3e5 + 5;
vector<vector<int>>adjList(MAXN);
vector<int>counts(MAXN);
vector<bool>done(MAXN, false);
int ans = 0;

void dfs(int u, int p) {
   
    for (auto v : adjList[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (!done[v] && !done[u]) {
            done[v] = true;
            done[u] = true;
            ans++;
        }
    }

}

void solve(int t) {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
        
    }
    dfs(1, -1);
    cout << ans << endl;

    
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