#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    
    int n;
    cin>>n;
    vector<int>a(n);
    long long ans=0;
    cin >>a[0];
    for (int i=1;i<n;i++) {
        cin>>a[i];
        if (a[i]<a[i-1]) {
            ans+=a[i-1]-a[i];
            a[i]= a[i-1];
        }
    }
    cout<<ans<<endl;
    
}
 
 
int main() {
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