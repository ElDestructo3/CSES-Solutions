#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    
    int n;
    cin>>n;
    if (n==1) {
        cout<<1<<endl;
        return;
    }
    if (n == 2 || n == 3) {
        cout<<"NO SOLUTION";
        return;
    }
    for (int i=(n+1)/2-1;i>=0;i--) {
        cout<<2*i+1<<" ";
    }
    for (int i=(n)/2;i>0;i--) {
        cout<<2*i<<" ";
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