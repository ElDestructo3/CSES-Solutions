#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    int x,n;
    cin>>x>>n;
    set<int>lights{0,x};
    multiset<int>sections{x};
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        auto front = lights.upper_bound(temp);
        auto back = front;
        back--;
        sections.erase(sections.find(*front-*back));
        sections.insert(*front-temp);
        sections.insert(temp-*back);
        lights.insert(temp);
        auto ans = sections.end();
        ans--;
        cout<<*ans<<" ";
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