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
        return a ^ b;
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
		seg[p += n] = val; 
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
    segTree<int> st;
    int n, q;
    cin >> n >> q;
    st.init(n+1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        st.upd(i,x);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        
            cout << st.query(x,y) << endl;
        
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