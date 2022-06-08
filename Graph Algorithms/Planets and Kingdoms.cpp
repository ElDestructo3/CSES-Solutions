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
vector<int> id(2e5 + 5);
vector<int> s;

void dfs(int x, int pass, vector<int>& visited, int num = 0) {
    visited[x] = true;
    vector<int> &temp = (pass == 1) ? adjacencyList[x] : reverseadjacencyList[x];
    for (auto e : temp) {
        if (!visited[e]) {
            dfs(e, pass, visited, num);
        }
    }
    s.push_back(x);
    if (pass == 2) {
        id[x] = num;
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
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, 1, visited);
        }
    }

    int components = 0;
    
    for (int i = n; i >= 1; i--) {
        if (!reverseVisited[s[i-1]]) {
            components++;
            dfs(s[i-1], 2, reverseVisited, components);
            
        }
    }
    cout << components << endl;
    for (int i = 1; i <= n; i++) {
        cout << id[i] << " ";
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