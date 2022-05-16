#include <bits/stdc++.h>
 
using namespace std;
 
 
void solve() {
    
    long long a,b,x,y;
    cin >> x >> y;
    a = max(x,y);
    b = min(x,y);
    if (a > 2*b) {
        cout<<"NO"<<endl;
        return;
    }
    if ((2*b-a)%3 == 0) {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
      
}
 
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long t;
    cin>>t;
    //t=1;
    while (t--) {
        solve();
    }
}