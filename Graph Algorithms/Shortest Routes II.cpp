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
const int INF = 1e13;


void solve(int t) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, INF));
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adjMatrix[a][b] = min(w, adjMatrix[a][b]);
        adjMatrix[b][a] = min(w, adjMatrix[b][a]);
    }
    
    for (int i = 1; i <= n; i++) {
        adjMatrix[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
            
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                
            }
        }
    }
    for (int i = 0; i < q; i++)  {
        int a, b;
        cin >> a >> b;
        cout << (adjMatrix[a][b] >= INF ? -1 : adjMatrix[a][b]) << endl;
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

 
 

