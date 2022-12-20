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
vector<vector<int>>adjList(MAXN), reverseAdjList(MAXN);
vector<bool> visited(MAXN, false);
vector<int> topological_order, comp(MAXN);

void dfs(int u) {
    visited[u] = true;
    for (const auto &v : adjList[u]) {
        if (!visited[v]) {
            //cout << v << endl; 
            dfs(v);
        }
    }
    topological_order.push_back(u);
    //cout << u << endl;
}

void stronglyConnectedComponents(int u, int id) {
    visited[u] = true;
    comp[u] = id;

    for (const auto &v : reverseAdjList[u]) {
        if (!visited[v]) {
            stronglyConnectedComponents(v, id);
        }
    }
}


void solve(int t) {
    
    
    int n, m;
    cin >> n >> m;

    while (n--) {
        int topping1, topping2;
        char preference1, preference2;
        cin >> preference1 >> topping1 >> preference2 >> topping2;
        bool pref1 = preference1 == '+';
        bool pref2 = preference2 == '+';
        // not a to b 
        int neg_a = topping1 - 1 + (pref1 ? m : 0);
        int a = topping1 - 1 + (pref1 ? 0 : m);
        int neg_b = topping2 - 1 + (pref2 ? m : 0);
        int b = topping2 - 1 + (pref2 ? 0 : m);
        adjList[neg_a].push_back(b);
        reverseAdjList[b].push_back(neg_a);
        // not b to a
        adjList[neg_b].push_back(a);
        reverseAdjList[a].push_back(neg_b);
        
    }

    

    for (int i = 0; i < 2 * m; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    fill(visited.begin(), visited.end(), false);
    reverse(topological_order.begin(), topological_order.end());

    int id = 0;
    for (const auto &v : topological_order) {
        if (!visited[v]) {
            stronglyConnectedComponents(v, id);
            id++;
        }
    }
    
    vector<int> ans(m);

    for (int i = 0; i < m; i++) {
        if (comp[i] == comp[i +m]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        ans[i] = comp[i] > comp[i + m];
    }

    for (int i = 0; i < m; i++) {
        cout << (ans[i] == 1 ? '+' : '-') << " ";
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
        
        solve(i + 1);
    }
    
    
    
}
