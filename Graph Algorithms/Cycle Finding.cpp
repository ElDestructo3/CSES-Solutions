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
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a,b, c;
        cin >> a >> b >> c;
        edges[i] = {a,b,c};
    }
    vector<int> distances(n+1, 1e10);
    int source = 1;
    distances[source]  = 0;
    vector<int> parents(n+1, -1);
    int x;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (int j = 0; j < m; j++) {
            if (distances[edges[j].src] + edges[j].weight < distances[edges[j].dest]) {
                distances[edges[j].dest] = distances[edges[j].src] + edges[j].weight;
                parents[edges[j].dest] = edges[j].src;
                x = edges[j].dest;
            }
        }
    }
    
    if (x != -1) {
        cout<<"YES"<<endl;
        int y = x;
        for (int i = 0; i < n; i++) {
           
            y = parents[y];
        }
        vector<int>path;
        for (int cur = y;; cur = parents[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1) {
                break;
            }
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            cout<<path[i]<<" ";
        }
    }
    else {
        cout << "NO" <<endl;
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