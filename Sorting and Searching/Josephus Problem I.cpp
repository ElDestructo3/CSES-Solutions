#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    int n;
    cin>>n;
    vector<bool> visited(n+1,false);
    int num=0;
    int index = 1;
    while (num<n-1) {
        int num_false=0;
        while (num_false < 2) {
            if (!visited[index]) num_false++;
            if (num_false==2) break;
            index++;
            if (index==n+1) {
                index=1;
            }
        }
        visited[index]=true;
        num++;
        cout<<index<<" ";
    }
    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            cout<<i<<endl;
            return;
        }
    }
    
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