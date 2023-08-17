#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
vector<pair<int,int>> dir = {{1,0}, {0,1}, {0,-1}, {-1,0}};
int MAXN = 3e5 + 5;
vector<vector<int>>adjList(MAXN), reverseAdjList(MAXN), condensedReverseAdjList(MAXN);
vector<bool> visited(MAXN, false);
vector<int> topological_order, comp(MAXN, -1), compValues(MAXN, 0), dp(MAXN, 0);

void dfs(int u) {
    visited[u] = true;
    for (const auto &v : adjList[u]) {
        if (!visited[v]) {
            //cout << v << endl; 
            dfs(v);
        }
    }
    topological_order.push_back(u);
    //cout << u << endl;
}

void stronglyConnectedComponents(int u, int id) {
    visited[u] = true;
    comp[u] = id;

    for (const auto &v : reverseAdjList[u]) {
        if (!visited[v]) {
            stronglyConnectedComponents(v, id);
        }
    }
}

int DP(int i) {
    if (dp[i]) return dp[i];

    dp[i] = compValues[i];
    for (auto v : condensedReverseAdjList[i]) {
        dp[i] = max(dp[i], DP(v) + compValues[i]);
    }
    return dp[i];
}

void solve(int t) {
    
    int n, m;
    cin >> n >> m;
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        reverseAdjList[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    reverse(topological_order.begin(), topological_order.end());
    fill(visited.begin(), visited.end(), false);
    int id = 0;
    for (auto v: topological_order) {
        if (comp[v] == -1) {
            stronglyConnectedComponents(v, id);
            id++;
        }
    }

    for (int i = 1; i <= n; i++) {
        compValues[comp[i]] += coins[i];
    }
    for (int i = 1; i <= n; i++) {
        for (auto v: adjList[i]) {
            if (comp[i] == comp[v]) continue;
            condensedReverseAdjList[comp[v]].push_back(comp[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < id; i++) {
        ans = max(ans, DP(i));
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
     
    
    int t=1;
    //cin>>t;
    
    for (int i =0; i<t;i++){
        
        solve(i + 1);
    }

}
