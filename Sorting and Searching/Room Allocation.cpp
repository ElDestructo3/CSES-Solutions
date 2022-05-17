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
 
    vector<pair<pair<int,int>,int>> times(n);
    for (int i = 0; i < n; i++) {
        cin>>times[i].first.first>>times[i].first.second;
        times[i].second=i;  
    }
    sort(times.begin(),times.end());
    vector<int>roomAssigned(n,-1);
    int roomID=1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> rooms;
    for (int i=0; i<n;i++) {
        if (rooms.size()==0) {
            roomAssigned[times[i].second] = roomID++;
            rooms.push({times[i].first.second,roomID-1});
        }
        else {
            if (rooms.top().first >= times[i].first.first) {
                roomAssigned[times[i].second] = roomID;
                rooms.push({times[i].first.second, roomID++});
            }
 
            else {
                roomAssigned[times[i].second] = rooms.top().second;
                rooms.pop();
                rooms.push({times[i].first.second,roomAssigned[times[i].second]});
            }
        }
    }
    cout<<roomID-1<<endl;
    for (int i=0;i<n;i++) {
        cout<<roomAssigned[i]<<" ";
 
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