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
void dfs(int u, int p, vector<int>& parents) {
    for (auto v : adjList[u]) {
        if (v == p) continue;
        parents[v] = u;
        dfs(v, u, parents);
    }

}

void solve(int t) {
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adjList[x].push_back(i);
        
    }
    vector<int> parents(n + 1, -1);
    parents[1] = -1;
    dfs(1, -1, parents);
    vector<vector<int>> ancestors(20, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        ancestors[0][i] = parents[i];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (ancestors[i - 1][j] == -1) {
                ancestors[i][j] = -1;
            }
            else {
                ancestors[i][j] = ancestors[i - 1][ancestors[i - 1][j]];
            }
        }
        
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int k = 19;
        while (k >= 0) {
            if (b & (1 << k)) {
                a = ancestors[k][a];
                if (a == -1) break;
            }
            k--;
        } 
        cout << a << endl;
    }
    


    
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