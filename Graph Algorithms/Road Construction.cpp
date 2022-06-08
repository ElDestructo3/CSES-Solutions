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


void make_set(int v, vector<int>& parent, vector<int>& rank) {
    parent[v] = v;
    rank[v] = 1;
}

int find_set(int v, vector<int>& parent) {
    if(parent[v] == v) return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find_set(u, parent);
    v = find_set(v, parent);
    if(u == v) return;
    if (rank[u] < rank[v]) {
        swap(u, v);
        
    }
    parent[v] = u;
    rank[u] += rank[v];
}

void solve(int t) {
    int n, m;
    cin >> n >> m;
    
    //Kruskal's Algorithm
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
    }
    vector<int> parent(n+1, 0);
    vector<int> rank(n+1, 0);
    for (int i = 1; i <= n; i++) {
        make_set(i, parent, rank);
    }
    int count = n;
    int max_size = 1;
    for (auto e: edges) {
        int u = e.first, v = e.second;
        if (find_set(u, parent) != find_set(v, parent)) {
            union_sets(u, v, parent, rank);
            count--;
            max_size = max(max_size, max(rank[find_set(u, parent)], rank[find_set(v, parent)]));
        }
        cout << count << " " << max_size << endl;
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