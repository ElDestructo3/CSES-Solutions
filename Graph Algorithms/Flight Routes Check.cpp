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


void dfs(int v, int direction, vector<int>& visited) {
    visited[v] = true;
    if (direction == 0) {
        for (auto e : adjacencyList[v]) {
            if (!visited[e]) {
                dfs(e, direction, visited);
            }
        }
    }
    else {
        for (auto e : reverseadjacencyList[v]) {
            if (!visited[e]) {
                dfs(e, direction, visited);
            }
        }
    }
}

void solve(int t) {
    int n, m;
    cin >> n >> m;
    
    vector<int> visited(n+1, false);
    vector<int> reverseVisited(n+1, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
        reverseadjacencyList[b].push_back(a);
    }
    dfs(1, 0, visited);
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return;
        }
    }
    
    dfs(1, 1, reverseVisited);
    for (int i = 2; i <= n; i++) {
        if (!reverseVisited[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return;
        }
    }
    cout << "YES" << endl;
    
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