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
//vector<bool> visited(MAXN, false);
vector<int> path, comp(MAXN, -1), compValues(MAXN, 0), dp(MAXN, 0);
unordered_map<string, int> visited_strings;
string ans;
vector<bool> visited(1002, false);

bool flow_reachable(vector<vector<int>>& adjMatrix, vector<int>& parents, int n) {

    fill(visited.begin(), visited.end(), false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = 0; j <= 1001; j++) {
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

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adjMatrix(1002, vector<int>(1002, 0));
    vector<vector<int>> adjMatrixCopy(1002, vector<int>(1002, 0));
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if (adjMatrix[a][500 + b] == 0) {
            adjMatrix[a][500 + b] += 1;
            adjMatrixCopy[a][500 + b] += 1;
        }
        
    }
    for (int i = 0; i < n; i++) {
       adjMatrix[0][i + 1]++;
       adjMatrixCopy[0][i + 1]++;
    }
    for (int i = 0; i < m; i++) {
        adjMatrix[i + 501][1001]++;
        adjMatrixCopy[i + 501][1001]++;
    }
    // Dinic max flow algorithm
    int max_flow = 0;

    vector<int> parents(1002);

    while (flow_reachable(adjMatrix, parents, n)) {
        int flow_increment = 1e18;
        int u, v;
        for (v = 1001; v != 0; v = parents[v]) {
            u = parents[v];
            //cout << "hi!" << endl;
            flow_increment = min(flow_increment, adjMatrix[u][v]);
        }
        if (flow_increment == 0) break;
        max_flow += flow_increment;
        for (v = 1001; v != 0; v = parents[v]) {
            u = parents[v];
            adjMatrix[u][v] -= flow_increment;
            adjMatrix[v][u] += flow_increment;
        }
    }

    flow_reachable(adjMatrix, parents, n);                   // another bfs to find the min cuts, consider i,j if one is reachable other isnt
    cout << max_flow << endl;
    for (int i = 1; i <= 500; i++) {
        for (int j = 501; j <= 1000; j++) {
            if (adjMatrixCopy[i][j] == 1 && adjMatrix[i][j] == 0) {
                cout << i << " " << j - 500 << endl;
            }
        }
    }
    // cout << ans.size() << endl;
    // for (auto it : ans) {
    //     cout << it.first << " " << it.second << endl;
    // }
    
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