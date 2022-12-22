#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
vector<pair<int,int>> dir = {{1,0}, {0,1}, {0,-1}, {-1,0}};
int MAXN = 3e5 + 5;
vector<vector<int>>adjList(MAXN), reverseAdjList(MAXN), condensedReverseAdjList(MAXN);
vector<bool> visited(MAXN, false);
vector<int> path, comp(MAXN, -1), compValues(MAXN, 0), dp(MAXN, 0);
unordered_map<string, int> visited_strings;
string ans;

void dfs(int u) {
    while (adjList[u].size()) {
        int v = adjList[u].back();
        adjList[u].pop_back();
        dfs(v);
    }
    path.push_back(u);

}


void solve(int t) {
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        reverseAdjList[--b].push_back(--a);
    }

    vector<vector<int>> bitmask_dp(1 << n, vector<int>(n));  // dp[S][i] is the number of paths travelling through all the cities in set s and ending at city i
    bitmask_dp[1][0] = 1;

    for (int s = 2; s < 1 << n; s++) {
        if ((s & 1) == 0) continue;  // if city 1 is not present in the set then ignore
        if ((s & (1 << (n - 1))) && s != (1 << n) - 1) continue;     // if city n is present then the set should be the complete set

        for (int end_vertex = 0; end_vertex < n; end_vertex++) {
            if ((s & (1 << end_vertex)) == 0)  continue;        // if end_vertex not present continue;
            int remaining_subset = s - (1 << end_vertex);
            for (auto v: reverseAdjList[end_vertex]) {
                if ((s & (1 << v))) {
                    bitmask_dp[s][end_vertex] += bitmask_dp[remaining_subset][v];
                    bitmask_dp[s][end_vertex] %= MOD1;
                }
            }
        }

    }
    cout << bitmask_dp[(1 << n) - 1][n - 1];

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
    
    for (int i = 0; i < t; i++){
        
        solve(i + 1);
    }

}