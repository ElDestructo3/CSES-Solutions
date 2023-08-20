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
 
class segmentTree {
 
    int n;
    int* backSegTree;
    int* frontSegTree;
    int outOfRange = INT_MAX;
    vector<int> array;
public:
    segmentTree(vector<int> a): n(a.size()), array(a) {
        backSegTree = new int[4 * n];
        frontSegTree = new int[4 * n];
        build(0, n - 1, 0);
    }

    int apply(int val1, int val2) {
        return min(val1, val2);
    }
 
    void build(int left, int right, int index) {
        if (left == right) {
            frontSegTree[index] = array[left] - left;
            backSegTree[index] = array[left] + left;
        }
        else {
            build(left, (left + right) / 2, 2 * index + 1);
            build((left + right) / 2 + 1, right, 2 * index + 2);
            frontSegTree[index] = apply(frontSegTree[2 * index + 1], frontSegTree[2 * index + 2]);
            backSegTree[index] = apply(backSegTree[2 * index + 1], backSegTree[2 * index + 2]);
        }
    }
 
    int apply_range(int index) {
        //return apply_internal(0, n - 1, left, right, 0);
        int val1 = apply_internal_front(0, n - 1, 0, index, 0);
        int val2 = apply_internal_back(0, n - 1, index, n - 1, 0);
        return min(val1 + index, val2 - index);

    }
 
    int apply_internal_front(int tree_left, int tree_right, int left, int right, int index) {
        if (tree_left == left && tree_right == right) {
            return frontSegTree[index];
        } 
        if (left > right) return outOfRange;
        int child1_left = tree_left, child1_right = (tree_left + tree_right) / 2;
        int child2_left = child1_right + 1, child2_right = tree_right;
        return apply(apply_internal_front(child1_left, child1_right, left, min(right, child1_right), 2 * index + 1) 
                , apply_internal_front(child2_left, child2_right, max(left, child2_left), right, 2 * index + 2));
    }

    int apply_internal_back(int tree_left, int tree_right, int left, int right, int index) {
        if (tree_left == left && tree_right == right) {
            return backSegTree[index];
        } 
        if (left > right) return outOfRange;
        int child1_left = tree_left, child1_right = (tree_left + tree_right) / 2;
        int child2_left = child1_right + 1, child2_right = tree_right;
        return apply(apply_internal_back(child1_left, child1_right, left, min(right, child1_right), 2 * index + 1) 
                , apply_internal_back(child2_left, child2_right, max(left, child2_left), right, 2 * index + 2));
    }
 
    void update(int array_index, int new_val) {
        update_internal(0, n - 1, array_index, new_val, 0);
    }
 
    void update_internal(int tree_left, int tree_right, int array_index, int new_val, int index) {
        if (tree_left == tree_right) {
            frontSegTree[index] = new_val - tree_left;
            backSegTree[index] = new_val + tree_left;
        }
        else {
            int mid = (tree_left + tree_right) / 2;
            if (mid >= array_index) {
                update_internal(tree_left, mid, array_index, new_val, 2 * index + 1);
            }
            else {
                update_internal(mid + 1, tree_right, array_index, new_val, 2 * index + 2);
            }
            frontSegTree[index] = apply(frontSegTree[2 * index + 1], frontSegTree[2 * index + 2]);
            backSegTree[index] = apply(backSegTree[2 * index + 1], backSegTree[2 * index + 2]);
        }
		//cout << tree_left << " " << tree_right << " " << segTree[index].first << " " << segTree[index].second << endl;
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
        int type, a, b;
        cin >> type;
        if (type == 1) {
            cin >> a >> b;
            segTree.update(a - 1, b);
        }
        else {
            cin >> a;
            cout << segTree.apply_range(a - 1) << endl;
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