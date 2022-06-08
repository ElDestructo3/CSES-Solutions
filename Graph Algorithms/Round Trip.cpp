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

void dfs(int u, vector<vector<int>>&G, vector<int>& p){
    for(int v : G[u]){
        if(v != p[u]){
            p[v] = u;
            dfs(v, G, p);
        }
    }
}

int find(int u, vector<int>& ds){
    if(ds[u] < 0)   return u;
    ds[u] = find(ds[u], ds);
    return ds[u];
}

bool merge(int u, int v, vector<int>& ds){
    u = find(u, ds); v = find(v, ds);
    if(u == v)  return false;
    if(ds[u] < ds[v])   swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}

void solve(int t) {

    int n,m;
    cin >> n >> m;
    vector<vector<int>>arr(n+1);
    vector<int> parent(n+1);
    vector<int> ds(n+1, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (!merge(a, b, ds)) {
            dfs(a, arr, parent);
            int u = b;
            stack<int> s;
            
            while (u!=0) {
                s.push(u);
                u = parent[u];
                
            }
            s.push(b);
            cout<<s.size()<<endl;
            while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
            }
            cout<<endl;
            return;
        }
        
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    
    cout<<"IMPOSSIBLE"<<endl;
   
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