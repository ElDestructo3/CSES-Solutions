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
int parent[(int) 2e5 + 5][30];

int jump(int a, int d) {
    for (int i = 0; i < 30; i++) {
        if (d & (1 << i)) {
            a = parent[a][i];
        }
    }
    return a;
}

void solve(int t) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> parent[i][0];
    }
    for (int i = 1; i <30; i++) {
        for (int j = 1; j <=n; j++) {
            parent[j][i] = parent[parent[j][i-1]][i-1];

        }
    }
    while (q--) {
        int a, d;
        cin >> a >> d;
        cout << jump(a, d) << endl;
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