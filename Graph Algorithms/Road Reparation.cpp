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
    rank[v] = 0;
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
    if (rank[u] == rank[v]) {
        rank[u]++;
    }
}

struct Edge {
    int u, v, w;
    bool operator<(Edge const& e) const {
        return w < e.w;
    }
};

void solve(int t) {
    int n, m;
    cin >> n >> m;
    /*
    vector<vector<pair<int,int>>> adjacencyList(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacencyList[u].push_back({v, w});
        adjacencyList[v].push_back({u ,w});
    }

    
    Prim's Algorithm
    int ans = 0;
    set<pair<int,int>> pq;
    int src = 1;
    vector<bool> mst(n+1, false);
    vector<int> min_edge(n+1, INT32_MAX);
    min_edge[src] = 0;
    pq.insert({0, 1});
    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }

        int vertex = pq.begin()->second;
        int weight = pq.begin()->first;

        pq.erase(pq.begin());
        
        mst[vertex] = true;
        ans += weight;
        for (auto edge : adjacencyList[vertex]) {
            if (!mst[edge.first] && min_edge[edge.first] > edge.second) {
                pq.erase({min_edge[edge.first], edge.first});
                pq.insert({edge.second, edge.first});
                min_edge[edge.first] = edge.second;

            }
        }
    }
    cout << ans << endl;*/
    //Kruskal's Algorithm
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    vector<int> parent(n+1, 0);
    vector<int> rank(n+1, 0);
    for (int i = 1; i <= n; i++) {
        make_set(i, parent, rank);
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    int count = 0;
    for (auto e: edges) {
        if (find_set(e.u, parent) != find_set(e.v, parent)) {
            union_sets(e.u, e.v, parent, rank);
            ans += e.w;
            count++;
        }
    }
    if (count == n-1) {
        cout << ans << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
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