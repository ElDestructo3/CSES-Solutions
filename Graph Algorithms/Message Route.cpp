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


void solve(int t) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    
    }
    vector<int>visited(n + 1, 0);
    vector<int> distances(n + 1, 0);
    visited[1] = true;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            if (!visited[next]) {
                visited[next] = cur;
                distances[next] = distances[cur] + 1;
                q.push(next);
            }
        }
    }
    if (visited[n] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    stack<int> st;
    int cur = n;
    while (cur != 1) {
        st.push(cur);
        cur = visited[cur];
    }
    st.push(1);
    cout<<st.size()<<endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
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

 
 
