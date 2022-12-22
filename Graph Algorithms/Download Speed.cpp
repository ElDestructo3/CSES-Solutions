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
vector<pair<int,int>> knight_dirs = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
int MAXN = 3e5 + 5;
vector<vector<int>>adjList(MAXN), reverseAdjList(MAXN), condensedReverseAdjList(MAXN);
vector<bool> visited(MAXN, false);
vector<int> path, comp(MAXN, -1), compValues(MAXN, 0), dp(MAXN, 0);
unordered_map<string, int> visited_strings;
string ans;

bool flow_reachable(vector<vector<int>>& adjMatrix, vector<int>& parents, int n) {
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = 1; j <= n; j++) {
            if (adjMatrix[u][j] && !visited[j]) {
                visited[j] = true;
                parents[j] = u;
                q.push(j);
            }
        }
    }
    return visited[n];
}

void solve(int t) {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjMatrix[a][b] += c;
    }
    // Dinic max flow algorithm
    int max_flow = 0;

    vector<int> parents(n + 1);

    while (flow_reachable(adjMatrix, parents, n)) {
        int flow_increment = 1e18;
        int u, v;
        for (v = n; v != 1; v = parents[v]) {
            u = parents[v];
            flow_increment = min(flow_increment, adjMatrix[u][v]);
        }
        max_flow += flow_increment;
        for (v = n; v != 1; v = parents[v]) {
            u = parents[v];
            adjMatrix[u][v] -= flow_increment;
            adjMatrix[v][u] += flow_increment;
        }
    }
    cout << max_flow << endl;
    
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