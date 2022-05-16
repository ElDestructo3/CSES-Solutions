#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    
    int n;
    cin>>n;
    int temp;
    vector<int>dp(n,0);
    for (int i=0;i<n-1;i++) {
        cin>>temp;
        dp[temp-1]++;
    }
    for (int i=0;i<n;i++) {
        if (!dp[i]) {
            cout<<i+1<<endl;
        }
    }
    
    
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