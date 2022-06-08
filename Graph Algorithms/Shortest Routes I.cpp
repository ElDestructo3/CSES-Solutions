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
    vector<vector<pair<int,int>>> adjList(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adjList[a].push_back({b,w});

    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distances(n+1, LONG_LONG_MAX);
    distances[1] = 0;
    pq.push({1, 0});
    while (!pq.empty()) {
        int node = pq.top().first;
        int dist = pq.top().second;
        pq.pop();
        if (dist != distances[node]) continue;
        for (auto e : adjList[node]) {
            int eNode = e.first;
            int eDist = e.second;
            if (distances[node] + eDist < distances[eNode]) {
                distances[eNode] = distances[node] + eDist;
                pq.push({eNode, distances[eNode]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout<<distances[i]<<" ";
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

 
 
