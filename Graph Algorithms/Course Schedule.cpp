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
const int INF = 1e17;

void dfs(int vertex, vector<vector<int>>& adjacencyList, vector<int>& visited, vector<int>& ans, int& cycle_start) {
    visited[vertex] = 1;
    for (auto u: adjacencyList[vertex]) {
        if (visited[u] == 0) {
            dfs(u, adjacencyList, visited, ans, cycle_start);
        }
        else if (visited[u] == 1) {
            cycle_start = u;
            break;
        }
        
    }
    visited[vertex] = 2;
    ans.push_back(vertex);
}
 
void solve(int t) {
 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjacencyList(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
    }
    vector<int> visited(n+1, false);
    vector<int> ans;
    int cycle_start = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adjacencyList, visited, ans, cycle_start);
        }
    }
    if (cycle_start != -1) {
        cout << "IMPOSSIBLE"<<endl;
        return;
    }
    reverse(ans.begin(), ans.end());
    for (auto v: ans) {
        cout << v << " ";
    }
    cout<<endl;
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

 
 
