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
 
template<class T> struct segTree {
    const T ID = 0;
 
    T comb(T a, T b) {
        return max(a, b);
    }
 
    int n;
    vector<T> seg;
 
    void init(int _n) { 
        n = _n; 
        seg.assign(2*n,ID); 
    }
 
	void pull(int p) { 
        seg[p] = comb(seg[2*p],seg[2*p+1]); 
    }
 
	void upd(int p, T val) { 
		seg[p += n] += val; 
        for (p /= 2; p; p /= 2) {
            pull(p);
        }
    }
 
	T query(int l, int r) {	
 
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
 
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);    
		}
 
		return comb(ra,rb);
	}  
};
 
void solve(int t) {
    int n, m;
    cin >> n >> m;
    segTree<int> st;
    st.init(n+1);
    for (int i = 0; i < n;i ++) {
        int temp;
        cin >> temp;
        st.upd(i+1, temp);

    }
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        int left = 1, right = n;
        //cout << st.query(left,right) << endl;
        if (st.query(1, n) < num) {
            cout << 0 << " ";
            continue;
        }
        while (left <= right) {
            if (left == right) {
                cout << left << " ";
                //cout << st.query(left, right) << endl;
                st.upd(left, - num);
                //cout << st.query(left, right) << endl;
                //for (int j = 1; j <= n; j++) {
                //    cout<< st.query(j, j)<< " ";
                //}
                //cout << endl;
                break;
            }
            int mid = (left + right) / 2;
            if (st.query(left,mid) >= num) {
                right = mid;
            } else {
                left = mid + 1;
            }
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