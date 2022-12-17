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

void solve(int t) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adjacencyList(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjacencyList[a].push_back({b, c});
    }
    vector<int> distances(n+1,INT64_MAX);
    vector<int> minPathLength(n+1, 0);
    vector<int> maxPathLength(n+1, 0);
    vector<int> numPaths(n+1, 0);
    vector<bool> visited(n+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    distances[1] = 0;
    numPaths[1] = 1;
   
    while (!pq.empty()) {
        int node = pq.top().second;
        int distance = distances[node];
        pq.pop();
        if (visited[node]) continue;
        visited[node] = true;
        
        for (auto e : adjacencyList[node]) {
            int dest = e.first;
            int weight = e.second;
            int temp1 = distance + weight;
            int temp2 = distances[dest];
            if (temp1 == distances[dest]) {
                numPaths[dest] = (numPaths[dest] + numPaths[node]) % MOD;
                
                minPathLength[dest] = min(minPathLength[dest], minPathLength[node] + 1);
                maxPathLength[dest] = max(maxPathLength[dest], maxPathLength[node] + 1);
                
                
            }

            else if (temp1 < distances[dest]) {
                distances[dest] = distance + weight;
                numPaths[dest] = numPaths[node];
                
                minPathLength[dest] = minPathLength[node] + 1;
                maxPathLength[dest] = maxPathLength[node] + 1;
                pq.push({distance + weight, dest});
            }
            
        }
    }
    cout << distances[n] << " " << numPaths[n] << " " << minPathLength[n] << " " << maxPathLength[n] << endl;
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