#include <bits/stdc++.h>
 
using namespace std;
 
 
void solve() {
    
    long long n;
    cin>>n;
    long long sum = (n*(n+1))/2;
    if (sum%2) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    if (n == 3) {
        cout<<1<<endl<<3<<endl<<2<<endl<<"1 2"<<endl;
        return;
    }
    long long target = sum/2;
    long long temp = 0;
    long long i = n;
    while (target - temp > n/2) {
        temp+=i--;
    }
    cout<<n-i+1<<endl;
    for (int j = n; j>i;j--) {
        cout<<j<<" ";
    }
    cout<<target - temp<<endl;
    cout<<i-1<<endl;
    for (int j = 1; j<=i;j++ ) {
        if (j == target - temp) continue;
        cout<<j<<" ";
    }
    cout<<endl;
      
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