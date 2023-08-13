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
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    vector<int> distances(n+1, INF);
    for (int i = 0; i < m; i++) {
        
        
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        edges[i].weight = - edges[i].weight;
    }
    
    int source = 1;
    distances[source]  = 0;
    
    if (n == 1 && m == 1) {
        cout << -1 << endl;
        return;
    }
    
    for (int i = 0; i < n-1; i++) {
        
        for (int j = 0; j < m; j++) {
            if (distances[edges[j].src] == INF) continue;
                
            distances[edges[j].dest] = min(distances[edges[j].src] + edges[j].weight, distances[edges[j].dest]);
            distances[edges[j].dest] = max(distances[edges[j].dest], -INF);
            
        }
    }
    for (int i = 0; i < n-1; i++) {
        
        for (int j = 0; j < m; j++) {
            if (distances[edges[j].src] == INF) continue;
            distances[edges[j].dest] = max(distances[edges[j].dest], -INF);
           
            if (distances[edges[j].dest] > distances[edges[j].src] + edges[j].weight)  {
                distances[edges[j].dest] = -INF;
            }
            
            
        }
    }
    
   
    if (distances[n] == -INF) {
        cout<< -1 <<endl;
    } else {
        cout<< -distances[n] <<endl;
    }
    return;
    
 
    
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
        
        solve();
    }
    
    
    
} 