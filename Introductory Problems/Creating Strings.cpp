#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    vector<string>v;
    do {
        v.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    cout<<v.size()<<endl;
    for(auto x:v) {
        cout<<x<<endl;
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