#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
int debug = 0;
#define cerr if(debug)cerr
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
void dfs(int u, int p, vector<int>& parents, vector<int>& distances) {
    for (auto v : adjList[u]) {
        if (v == p) continue;
        parents[v] = u;
        distances[v] = distances[u] + 1;
        dfs(v, u, parents, distances);
    }
 
}
 
// for each path a-b, we go a -> lca(a, b) -> b. The answer can be obtained for each node 
// by counting the number of paths that go in each subtree and adding them up. For each path
// a-b, we add 1 to dp[a] and dp[b] (as paths go through them). Note that by this path, all nodes get 
// added by 1 except lca, which gets added by 2 (as we sum through the subtrees and both a and
// b belong to the subtrees). So we need to decrease dp[lca(a,b)] by 1. Now for the parent of lca, 
// value will increase by 1 (due to the increase in lca) but path doesnt go through parent of lca, 
// so we need to decrease dp[parent[lca]] by 1. No other nodes are affected.
 
 
void dfs2(int u, int p, vector<int>& dp) {
    for (auto v: adjList[u]) {
        if (v == p) continue;
        dfs2(v, u, dp);
        dp[u] += dp[v];
    }
}
 
 
void solve(int t) {
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        
    }
    vector<int> parents(n + 1, -1);
    parents[1] = 1 ;
    vector<int> distances(n + 1, -1);
    distances[1] = 0;
    vector<int> dp(n + 1, 0);
    dfs(1, 1, parents, distances);
    vector<vector<int>> ancestors(20, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        ancestors[0][i] = parents[i];
        cerr << i << ": " << distances[i] << endl;
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            ancestors[i][j] = ancestors[i - 1][ancestors[i - 1][j]];
        }
        
    }
    auto jump = [&](int node, int jump) {
            int k = 19;
            while (k >= 0) {
                if (jump & (1 << k)) {
                    node = ancestors[k][node];
                }
                k--;
            }
            return node;
    };
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int a_og = a, b_og = b;
        if (distances[a] < distances[b]) {
            swap(a, b);
        }
        a = jump(a, distances[a] - distances[b]);
        int lca;
        if (a == b) {
            lca = a;
        }
        else {
            for (int k = 19; k >= 0; k--) {
                int a_new = ancestors[k][a];
                int b_new = ancestors[k][b];
                if (a_new != b_new) {
                    a = a_new;
                    b = b_new;
                }
            }
            lca = ancestors[0][a];
        }
    
        dp[a_og]++;
        dp[b_og]++;
        dp[lca]--;
        if (lca != 1) dp[parents[lca]]--;
 
    }
    for (int i = 1; i <= n; i++) {
        cerr << dp[i] << " ";
    }
    cerr << endl;
    dfs2(1, -1, dp);
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    
 
 
    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
     
    
    int t=1;
    //cin>>t;
    
    for (int i =0; i<t;i++){
        
        solve(i);
    }
    
    
    
}