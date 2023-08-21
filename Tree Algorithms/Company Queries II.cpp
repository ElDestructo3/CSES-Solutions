#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

int debug = 0;
#define cerr if(debug)cerr
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
void dfs(int u, int p, vector<int>& parents, vector<int>& distances) {
    for (auto v : adjList[u]) {
        if (v == p) continue;
        parents[v] = u;
        distances[v] = distances[u] + 1;
        dfs(v, u, parents, distances);
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
    parents[1] = 1 ;
    vector<int> distances(n + 1, -1);
    distances[1] = 0;
    dfs(1, 1, parents, distances);
    vector<vector<int>> ancestors(20, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        ancestors[0][i] = parents[i];
        cerr << i << ": " << parents[i] << endl;
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            ancestors[i][j] = ancestors[i - 1][ancestors[i - 1][j]];
        }
        
    }
    auto jump = [&](int node, int jump) {
            int k = 19;
            while (k >= 0) {
                if (jump & (1 << k)) {
                    node = ancestors[k][node];
                }
                k--;
            }
            return node;
    };
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        cerr << distances[a] << " " << distances[b] << endl;
        if (distances[a] < distances[b]) {
            swap(a, b);
        }
        cerr << distances[a] << " " << distances[b] << endl;
        a = jump(a, distances[a] - distances[b]);
        cerr << a << " " << b << endl;
        if (a == b) {
            cout << a << endl;
            continue;
        }
        for (int k = 19; k >= 0; k--) {
            int a_new = ancestors[k][a];
            int b_new = ancestors[k][b];
            if (a_new != b_new) {
                a = a_new;
                b = b_new;
            }
            cerr << a << " " << b << endl;
        }
        cout << ancestors[0][a] << endl;

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