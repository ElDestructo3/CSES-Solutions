#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    
    string s;
    cin>>s;
    int n = s.size();
    int ans = 1;
    int temp = 1;
    for (int i=1;i<n;i++) {
        if (s[i]==s[i-1]) {
            temp++;
        }
        else {
            ans=max(ans,temp);
            temp=1;
        }
    }
    ans=max(ans,temp);
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