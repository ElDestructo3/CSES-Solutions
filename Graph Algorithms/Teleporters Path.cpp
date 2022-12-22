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
vector<int> path, comp(MAXN, -1), compValues(MAXN, 0), dp(MAXN, 0);
unordered_map<string, int> visited_strings;
string ans;

void dfs(int u) {
    while (adjList[u].size()) {
        int v = adjList[u].back();
        adjList[u].pop_back();
        dfs(v);
    }
    path.push_back(u);

}


void solve(int t) {
    
    int n, m;
    cin >> n >> m;

    vector<int> in_degree(n + 1, 0), out_degree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        out_degree[a]++;
        in_degree[b]++;
        adjList[a].push_back(b);
    }
    int start_index = 0, end_index = 0;
    int num_zero_degree = 0, num_one_degree = 0, num_minusone_degree = 0;

    for (int i = 1; i <= n; i++) {
        int net = in_degree[i] - out_degree[i];
        if (net == 0) num_zero_degree++;
        if (net == 1) {
            num_minusone_degree++;
            end_index = i;
        }
        if (net == -1) {
            num_one_degree++;
            start_index = i;
        }
    }
    if (num_zero_degree == n || (num_zero_degree == n - 2 && start_index == 1 && end_index == n)) {
        dfs(1);
    }
    else {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    if (path.size() != m + 1 || path[0] != n || path[path.size() - 1] != 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
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
    
    for (int i = 0; i < t; i++){
        
        solve(i + 1);
    }

}