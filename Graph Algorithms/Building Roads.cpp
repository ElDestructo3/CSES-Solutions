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

int find(int a, vector<int>& disjointSet) {
    if (disjointSet[a] < 0) return a; 
    disjointSet[a] = find(disjointSet[a], disjointSet);
    return disjointSet[a];
    
    
}

bool merge(int a, int b, vector<int>& disjointSet) {
    a = find(a, disjointSet), b = find(b, disjointSet);
    if(a == b) return false;
    if (disjointSet[a] < disjointSet[b]) {
        swap(a,b);
    }
    disjointSet[b] += disjointSet[a];
    disjointSet[a] = b;
    return true;
    
}
void solve(int t) {
    int n, m;
    cin >> n >> m;
    vector<int> disjointSet(n + 1,-1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b, disjointSet);
    
    }
    vector<pair<int,int>>ans;
    for (int i = 1; i < n; i++) {
        if (merge(i, i+1, disjointSet)) {
            ans.push_back({i, i+1});
        }
    }
    cout << ans.size() << endl;
    for (auto& x : ans) {
        cout << x.first << " " << x.second << endl;
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

 
 
