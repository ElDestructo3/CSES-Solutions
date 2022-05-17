#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>x(n+1);
    vector<int>pos(n+1);
    
    for (int i=1;i<=n;i++) {
        cin>>x[i];
        pos[x[i]]=i;
        
    }
  
    int count=1;
  
    for (int i=2;i<=n;i++) {
        if (pos[i]<pos[i-1]) {
            count++;
        }
        else {
            
        }
    }
    pos[0]=0;
    pos[n+1]=n+1;
    //cout<<count<<endl;
    int a,b;
    for (int i=0;i<m;i++) {
        cin>>a>>b;
        if (pos[x[a]] < pos[x[a]-1] && b >= pos[x[a]-1]) count--;
        if (pos[x[a]] >= pos[x[a]-1] && b < pos[x[a]-1]) count++;
        if (pos[x[a]+1] < pos[x[a]] && b <= pos[x[a]+1]) count--;
        if (pos[x[a]+1] >= pos[x[a]] && b > pos[x[a]+1]) count++;
        pos[x[a]]=b;
        if(pos[x[b]-1] <= pos[x[b]] && a < pos[x[b]-1]) count++;
        if(pos[x[b]-1] > pos[x[b]] && a >= pos[x[b]-1]) count--;
        if(pos[x[b]+1] >= pos[x[b]] && a > pos[x[b]+1]) count++;
        if(pos[x[b]+1] < pos[x[b]] && a <= pos[x[b]+1]) count--;
        pos[x[b]] = a;
        swap(x[a], x[b]);
        cout<<count<<endl;
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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