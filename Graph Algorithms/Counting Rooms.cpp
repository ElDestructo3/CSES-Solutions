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
 
void dfs(vector<string>& grid, vector<vector<bool>>&visited, int i, int j, int n, int m) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int x = i + dir[k].first, y = j + dir[k].second;
        if (x>=0 && x < n && y>=0 && y <m && !visited[x][y]) {
            dfs(grid, visited, x, y, n, m);
        }
    }
}
 
void solve(int t) {
    int n,m;
    cin >> n >> m;
    vector<string>grid(n);
    vector<vector<bool>>visited(n, vector<bool>(m,false));
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            visited[i][j] = (grid[i][j] == '#');
        }
    }
    
    
 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            if (!visited[i][j]) {
                //cout<<i<<" "<<j<<endl;
                dfs(grid, visited, i, j, n, m);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
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