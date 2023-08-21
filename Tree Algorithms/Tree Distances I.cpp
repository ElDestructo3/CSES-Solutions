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
int K = 25;
int MAXN = 3e5 + 5;
vector<vector<int>>adjList(MAXN);
 
void dfs(int u, int p, vector<int>& distances) {
    for (auto v : adjList[u]) {
        if (v == p) continue;
        distances[v] = min(distances[u] + 1, distances[v]);
        //cerr << v << " " << distances[v] << endl;
        dfs(v, u, distances);
    }
 
}
 
void solve(int t) {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
 
    vector<int> distances(n + 1, INT_MAX);
    distances[1] = 0;
    dfs(1, -1, distances); 
    int far_node = max_element(distances.begin() + 1, distances.begin() + n + 1) - distances.begin();
    cerr << far_node << endl;
    distances.assign(n + 1, INT_MAX);
    distances[far_node] = 0;
    dfs(far_node, -1, distances);
    vector<int> new_distances(n + 1, INT_MAX);
    int second_far_node = max_element(distances.begin() + 1, distances.begin() + n + 1) - distances.begin();
    new_distances[second_far_node] = 0;
    dfs(second_far_node, -1, new_distances);
    for (int i = 1; i <= n; i++) {
        cout << max(distances[i], new_distances[i]) << " ";
    }
    cout << endl;   
 
    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
     
    
    int t=1;
    //cin>>t;
    
    for (int i =0; i<t;i++){
        
        solve(i);
    }
    
    
    
}   