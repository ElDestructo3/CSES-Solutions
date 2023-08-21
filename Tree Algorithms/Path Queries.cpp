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

class segmentTree {
 
    int n;
    long long* segTree;
    int outOfRange = 0;
    vector<int> array;
public:
    segmentTree(vector<int> a): n(a.size()), array(a) {
        segTree = new long long[4 * n];
        build(0, n - 1, 0);
    }
private:
    long long apply(int val1, int val2) {
        return val1 + val2;
    }
 
    void build(int left, int right, int index) {
        if (left == right) {
            segTree[index] = array[left];
        }
        else {
            build(left, (left + right) / 2, 2 * index + 1);
            build((left + right) / 2 + 1, right, 2 * index + 2);
            segTree[index] = apply(segTree[2 * index + 1], segTree[2 * index + 2]);
        }
    }
    long long apply_internal(int tree_left, int tree_right, int left, int right, int index) {
        if (tree_left == left && tree_right == right) {
            return segTree[index];
        } 
        if (left > right) return outOfRange;
        int child1_left = tree_left, child1_right = (tree_left + tree_right) / 2;
        int child2_left = child1_right + 1, child2_right = tree_right;
        return apply(apply_internal(child1_left, child1_right, left, min(right, child1_right), 2 * index + 1) 
                , apply_internal(child2_left, child2_right, max(left, child2_left), right, 2 * index + 2));
    }

    void update_internal(int tree_left, int tree_right, int array_index, int new_val, int index) {
        if (tree_left == tree_right) {
            segTree[index] = new_val;
        }
        else {
            int mid = (tree_left + tree_right) / 2;
            if (mid >= array_index) {
                update_internal(tree_left, mid, array_index, new_val, 2 * index + 1);
            }
            else {
                update_internal(mid + 1, tree_right, array_index, new_val, 2 * index + 2);
            }
            segTree[index] = apply(segTree[2 * index + 1], segTree[2 * index + 2]);
        }
    }
public:
    long long apply_range(int left, int right) {
        return apply_internal(0, n - 1, left, right, 0);
    }

    void update(int array_index, int new_val) {
        update_internal(0, n - 1, array_index, new_val, 0);
    }

};

void dfs(int u, int p, vector<int>& path, vector<int>& size, vector<int>& vals) {
    size[u] = 1;
    if (u != 1) vals[u] += vals[p];
    path.push_back(u);
    for (auto v : adjList[u]) {
        if (v == p) continue;
        dfs(v, u, path, size, vals);
        size[u] += size[v];
    }

}

void solve(int t) {
    int n, q;
    cin >> n >> q;
    vector<int> vals(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> vals[i + 1];
    }
    vector<int> vals_copy = vals;
    for(int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        
    }
    vector<int> path(1, 0), size(n + 1);
    dfs(1, -1, path, size, vals);
    map<int, int> path_idx;
    for (int i = 1; i <= n; i++) {
        path_idx[path[i]] = i;
    }

    vector<int> node_vals(n + 1);
    node_vals[0] = 0;
    for (int i = 1; i <= n; i++) {
        node_vals[i] = vals[path[i]];
    }
    vector<int> new_node_vals(n + 1);
    new_node_vals[0] = 0;
    for (int i = 1; i <= n; i++) {
        new_node_vals[i] = node_vals[i] - node_vals[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cerr << new_node_vals[i] << " ";
    }
    cerr << endl;
    segmentTree segTree = segmentTree(new_node_vals);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 2) {
            int node;
            cin >> node;
            int index = path_idx[node];
            cout << segTree.apply_range(0, index) << endl;
        }
        else {
            int node, val;
            cin >> node >> val;
            int index = path_idx[node];
            int right = index + size[node] - 1;
            int val_increase = val - vals_copy[node];
            cerr << val_increase << " " << right << endl;
            vals_copy[node] = val;
            if (right < n) {
                segTree.update(right + 1, new_node_vals[right + 1] - val_increase);
                new_node_vals[right + 1] -= val_increase;
            }
            segTree.update(index, new_node_vals[index] + val_increase);
            new_node_vals[index] += val_increase;
        }
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
