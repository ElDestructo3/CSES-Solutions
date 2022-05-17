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
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> times(n);
    for (int i=0;i<n;i++) {
        cin>>times[i].first>>times[i].second;
    }
    sort(times.begin(),times.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    });
    set<pair<int,int>> people;
    //for (int i=0;i<n;i++) {
    //    cout<<times[i].first<<" "<<times[i].second<<endl;
    //}
    int ans=0;
    for (int i=0;i<n;i++) {
        if (people.size()==0) {
            people.insert({-times[i].second,i}); 
        }
        else {
            auto it = people.lower_bound({-times[i].first,-1});
            if (it!=people.end()) {
                people.erase(it);
                people.insert({-times[i].second,i});
            }
            else if (it==people.end() && people.size()<k){
                    people.insert({-times[i].second,i});
            }
            else {
                ans++;
            }
            
        }
    }
    cout<<n-ans<<endl;
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