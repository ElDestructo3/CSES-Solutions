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
vector<vector<pair<int,int>>>adjList(MAXN), reverseAdjList(MAXN), condensedReverseAdjList(MAXN);
vector<bool> visited(MAXN, false);
vector<int> topological_order, comp(MAXN, -1), compValues(MAXN, 0), dp(MAXN, 0);

void solve(int t) {
    
    int n, m;
    cin >> n >> m;
    vector<int> visited_edge(m, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back({b, i});
        adjList[b].push_back({a, i});
    }

    for (int i = 1; i <= n; i++) {
        if (adjList[i].size() % 2 == 1) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    stack<int> cycle_stack;
    cycle_stack.push(1);
    vector<int> path;
    while (!cycle_stack.empty()) {
            int v = cycle_stack.top();
        //cycle_stack.pop();
        bool edge_present = false;
        while (!adjList[v].empty()) {
            int dest =  adjList[v].back().first;
            int edge_num = adjList[v].back().second;
            adjList[v].pop_back();
            if (!visited_edge[edge_num]) {
                cycle_stack.push(dest);
                visited_edge[edge_num] = true;
                edge_present = true;
                break;
            }
        }
        if (!edge_present) {
            path.push_back(v);
            cycle_stack.pop();
        }
    }

    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (auto i : path) {
        cout << i << " "; 
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
        
        solve(i + 1);
    }

}