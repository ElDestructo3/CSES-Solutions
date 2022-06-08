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

bool dfs(vector<vector<int>>& adjacencyList, vector<int>& parent, vector<int>& color, int vertex, int& cycle_start, int& cycle_end) {
    color[vertex] = 1;
    for (auto u: adjacencyList[vertex]) {
        if (color[u] == 0) {
            parent[u] = vertex;
            if (dfs(adjacencyList, parent, color, u, cycle_start, cycle_end)) return true;
        }
        else if (color[u] == 1) {
            cycle_start = u;
            cycle_end = vertex;
            return true;
        }
        
    }
    color[vertex] = 2;
    return false;
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
    vector<int> color(n+1, 0);
    vector<int> parent(n+1, -1);
    int cycle_start = -1, cycle_end;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && dfs(adjacencyList, parent, color, i, cycle_start, cycle_end)) break;
    }
    if (cycle_start == -1) {
        cout << "IMPOSSIBLE"<<endl;
        return;
    }
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v!= cycle_start; v = parent[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    cout<<cycle.size()<<endl;
    for (int v: cycle) {
        cout << v << " ";
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

 
 
