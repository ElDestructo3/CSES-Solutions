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
 
    int n,m;
    cin >> n >> m;
    vector<vector<int>>arr(n+1);
    vector<int> visited(n+1,false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    vector<int> team(n+1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            team[i] = 1;
            queue<int>q;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (auto x : arr[cur]) {
                    if (!visited[x]) {
                        visited[x] = true;
                        team[x] = 3 - team[cur];
                        q.push(x);
                    }
                    else {
                        if (team[x] == team[cur]) {
                            cout << "IMPOSSIBLE" << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <=n ;i++) {
        cout << team[i] << " ";
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