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

void dfs(int u, int p, vector<int>& distances, vector<int>& subtreeSize, vector<int>& parents) {
    subtreeSize[u] = 1;
    for (auto v : adjList[u]) {
        if (v == p) continue;
        distances[v] = min(distances[u] + 1, distances[v]);
        parents[v] = u;
        //cerr << v << " " << distances[v] << endl;
        dfs(v, u, distances, subtreeSize, parents);
        subtreeSize[u] += subtreeSize[v];
    }

}

void dfs2(int u, int p, int n, vector<int>& subtreeSize, vector<int>& ans_all) {
    for (auto v : adjList[u]) {
        if (v == p) continue;
        //cerr << v << " " << distances[v] << endl;
        ans_all[v] = ans_all[u] + n - 2 * subtreeSize[v];
        dfs2(v, u, n, subtreeSize, ans_all);
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
    vector<int> subtreeSize(n + 1, 0);
    vector<int> parents(n + 1, -1);
    distances[1] = 0;
    parents[1] = 1;
    dfs(1, -1, distances, subtreeSize, parents); 
    int ans = accumulate(distances.begin() + 1, distances.begin() + n + 1, 0LL);
    vector<int> ans_all(n + 1, -1);
    ans_all[1] = ans;
    dfs2(1, -1, n, subtreeSize, ans_all);
    for (int i = 1; i <= n; i++) {
        cout << ans_all[i] << " ";
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