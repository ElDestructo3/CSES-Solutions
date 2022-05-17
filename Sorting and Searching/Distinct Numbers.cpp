#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void solve() {
    
    set<int> arr;
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        arr.insert(temp);
    }
    cout<<arr.size()<<endl;
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