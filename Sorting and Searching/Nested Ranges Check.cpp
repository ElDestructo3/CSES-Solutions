#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;
 
#define int long long
 
void solve() {
    int n;
    cin>>n;
    
    vector<tuple<int,int,int>> pairs(n);
    for (int i=0;i<n;i++ ){
        int x,y;
        cin>>x>>y;
        pairs[i] = {x,y,i};
    }
    sort(pairs.begin(),pairs.end(), [](tuple<int,int,int> a, tuple<int,int,int> b) {
        return (get<0>(a)==get<0>(b)) ? get<1>(a) > get<1>(b) : get<0>(a) < get<0>(b);
    });
   /* for (int i=0;i<n;i++) {
        cout<<pairs[i].first<<" "<<pairs[i].second<<endl;
    }*/
    int maxR = 0, minR = INT_MAX;
    vector<bool>contained(n,0), contains(n,0);
    for (int i=0;i<n;i++) {
        if (get<1>(pairs[i])<=maxR) {
            contained[get<2>(pairs[i])]=1;
        }
        else {
            maxR = get<1>(pairs[i]);
        }
        if (get<1>(pairs[n-1-i])>=minR) {
            contains[get<2>(pairs[n-1-i])]=1;
        }
        else {
            minR = get<1>(pairs[n-1-i]);
        }
    }
    for (int i=0;i<n;i++) {
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<n;i++) {
        cout<<contained[i]<<" ";
    }
    cout<<endl;
    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long t=1;
    //cin>>t;
  
    while (t--) {
        solve();
    }
    
    
}
 