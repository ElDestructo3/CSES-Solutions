#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>desired(n);
    vector<int> apartments(m);
    for(int i=0;i<n;i++)cin>>desired[i];
    for(int i=0;i<m;i++)cin>>apartments[i];
    
    sort(desired.begin(),desired.end());
    sort(apartments.begin(),apartments.end());
    int ans=0;
    int i=0,j=0;
    while (i<n) {
        while (j<m && apartments[j]<desired[i]-k)j++;
        if (j<m && desired[i]-k<=apartments[j] && apartments[j]<=desired[i]+k) {
            ans++;
            j++;
            i++;
        }
        else {
            i++;
        }
    }
    cout<<ans<<endl;
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