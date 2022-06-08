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

typedef struct {
    int src, dest, weight;
} edge;

void solve(int t) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adjacencyList(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjacencyList[a].push_back({b, c});
    }
    vector<vector<int>> distances(n+1, vector<int>(k, INF));

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int start = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        if (distance > distances[start][k-1]) continue;
        for (auto e: adjacencyList[start]) {
            int node = e.first;
            int edge = e.second;
            if (distance + edge < distances[node][k-1]) {
                distances[node][k-1] = distance + edge;
                sort(distances[node].begin(), distances[node].end());
                pq.push({distance + edge, node});
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << distances[n][i] << " ";
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

 
 
