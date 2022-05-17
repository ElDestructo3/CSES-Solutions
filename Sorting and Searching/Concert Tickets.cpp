#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    int n,m;
    //vector<int>tickets(n);
    cin>>n>>m;
    multiset<int>tickets_set;
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        tickets_set.insert(-temp);
    }
    
    for (int i=0;i<m;i++) {
        int temp;
        cin>>temp;
        if (tickets_set.lower_bound(-temp)!=tickets_set.end()) {
            cout<<-*tickets_set.lower_bound(-temp)<<endl;
            tickets_set.erase(tickets_set.lower_bound(-temp));
        }
        else {
            cout<<-1<<endl;
        }
    }
    
   
}
 
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long t;
    //cin>>t;
    t=1;
    while (t--) {
        solve();
    }
    
    
}