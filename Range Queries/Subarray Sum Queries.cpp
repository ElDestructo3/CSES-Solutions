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
int K = 25;
int MAXN = 2e5 + 5;
 
typedef struct node {
    int sum;
    int max_prefix;
    int max_suffix;
    int max_subarray;
} node;

class segmentTree {
 
    int n;
    node* segTree;
    node outOfRange = {0, INT_MIN, INT_MIN, INT_MIN};
    vector<int> array;
public:
    segmentTree(vector<int> a): n(a.size()), array(a) {
        segTree = new node[4 * n];
        build(0, n - 1, 0);
    }

    node apply(node val1, node val2) {
        int new_sum = val1.sum + val2.sum;
        int new_prefix = max(val1.max_prefix, val1.sum + val2.max_prefix);
        int new_suffix = max(val2.max_suffix, val1.max_suffix + val2.sum);
        int new_subarr = max(max(val1.max_suffix + val2.max_prefix, val1.max_subarray),val2.max_subarray);
        return {new_sum, max(0LL, new_prefix), max(0LL, new_suffix), max(0LL, new_subarr)};
    }
 
    void build(int left, int right, int index) {
        if (left == right) {
            segTree[index] = {array[left], max(0LL, array[left]), max(0LL, array[left]), max(0LL, array[left])};
        }
        else {
            build(left, (left + right) / 2, 2 * index + 1);
            build((left + right) / 2 + 1, right, 2 * index + 2);
            segTree[index] = apply(segTree[2 * index + 1], segTree[2 * index + 2]);
        }
		//cout << left << " " << right << " " << segTree[index].first << " " << segTree[index].second << endl;
    }
 
    int apply_range(int left, int right) {
        return apply_internal(0, n - 1, left, right, 0).max_subarray;
    }
 
    node apply_internal(int tree_left, int tree_right, int left, int right, int index) {
        if (tree_left == left && tree_right == right) {
            return segTree[index];
        } 
        if (left > right) return outOfRange;
        int child1_left = tree_left, child1_right = (tree_left + tree_right) / 2;
        int child2_left = child1_right + 1, child2_right = tree_right;
        return apply(apply_internal(child1_left, child1_right, left, min(right, child1_right), 2 * index + 1) 
                , apply_internal(child2_left, child2_right, max(left, child2_left), right, 2 * index + 2));
    }
 
    void update(int array_index, int new_val) {
        update_internal(0, n - 1, array_index, new_val, 0);
    }
 
    void update_internal(int tree_left, int tree_right, int array_index, int new_val, int index) {
        if (tree_left == tree_right) {
            segTree[index] = {new_val, max(0LL, new_val), max(0LL, new_val), max(0LL, new_val)};
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
 
};
 
void solve(int t) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &v : a) {
        cin >> v;
    }
    
    segmentTree segTree = segmentTree(a);
    while (q--) {
        int k, x;
        cin >> k >> x;
        segTree.update(k - 1, x);
        cout << segTree.apply_range(0, n - 1) << endl;
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