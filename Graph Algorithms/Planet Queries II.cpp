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
    int n, q;
    cin >> n >> q;
    vector<int> next(n+1);
    vector<vector<int>> adjacencyList(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> next[i];
        adjacencyList[next[i]].push_back(i);
    }
    vector<map<int,int>> cycles;
    vector<int> cycleID(n+1, -2);
    for (int i = 1; i <= n; i++) {
        if (cycleID[i] != -2) continue;
        vector<int> path{i};
        int cur = i;
        while (cycleID[next[cur]] == -2) {
            cur = next[cur];
            cycleID[cur] = -3;
            path.push_back(cur);
        }
        map<int,int> cycle;
        bool inCycle = false;
        for (int p : path) {
            inCycle = inCycle || p == next[cur];
            if (inCycle) {
                cycle[p] = cycle.size();
            }
            cycleID[p] = inCycle ? cycles.size() : -1;
            
        }
        cycles.push_back(cycle);

    }

    vector<int> cycleDistance(n+1);
    for (int i = 1; i <= n; i++) {
        if (cycleID[next[i]] == -1 || cycleID[i] != -1) continue;
        cycleDistance[i] = 1;
        vector<int> stack(adjacencyList[i]);
        while (!stack.empty()) {
            int curr = stack.back();
            stack.pop_back();
            cycleDistance[curr] = cycleDistance[next[curr]] + 1;
            stack.insert(stack.end(), adjacencyList[curr].begin(), adjacencyList[curr].end());
        }
    }

    int depth = ceil(log2(n));
    vector<vector<int>> pow2Ends(n+1, vector<int>(depth + 1));
    for (int i = 1; i <= n; i++) {
        pow2Ends[i][0] = next[i];
    }
    for (int i = 1; i <= depth; i++) {
        for (int j = 1; j <= n; j++) {
            pow2Ends[j][i] = pow2Ends[pow2Ends[j][i-1]][i-1];
        }
    }


    auto advance = [&] (int a, int d) {
        for (int i = depth; i >= 0; i--) {
            if (d & (1 << i)) {
                a = pow2Ends[a][i];
            }
        }
        return a;
    };

    while (q--) {
        int u, v;
        cin >> u >> v;
        if (cycleID[pow2Ends[u][depth]] != cycleID[pow2Ends[v][depth]]) {
            cout << -1 << endl;
            continue;
        }
        if (cycleID[u] != -1 || cycleID[v] != -1) {
            if (cycleID[u] != -1 && cycleID[v] == -1) {
                cout << -1 << endl;
                continue;
            }
            int dist = cycleDistance[u];
            int u_cyc = advance(u, dist);
            map<int, int>& cyc = cycles[cycleID[u_cyc]] ;
            int u_ind = cyc[u_cyc];
            int v_ind = cyc[v];
            int diff = u_ind <= v_ind ? v_ind - u_ind : cyc.size() - (u_ind - v_ind);
            cout << dist + diff << endl;
        }

        else {
            if (cycleDistance[v] > cycleDistance[u]) {
                cout<< -1 << endl;
                continue;
            }
            int diff = cycleDistance[u] - cycleDistance[v];
            cout << (advance(u, diff) == v ? diff : -1 ) << endl;
        }

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