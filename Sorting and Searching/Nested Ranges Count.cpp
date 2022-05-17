#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
 
void solve() {
    int n;
    cin>>n;
    
    vector<tuple<int,int,int>> pairs(n);
    ordered_set<pair<int,int>> rightBoundaries;
    vector<int>contained(n), contains(n);
 
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
    
    for (int i=0;i<n;i++) {
        rightBoundaries.insert({get<1>(pairs[i]),-i});
        contained[get<2>(pairs[i])] = rightBoundaries.size() - rightBoundaries.order_of_key({get<1>(pairs[i]),-i}) -1;
    }
    rightBoundaries.clear();
    for (int i=n-1;i>=0;i--) {
        rightBoundaries.insert({get<1>(pairs[i]),-i});
        contains[get<2>(pairs[i])] =  rightBoundaries.order_of_key({get<1>(pairs[i]),-i});
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