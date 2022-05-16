#include <bits/stdc++.h>
 
using namespace std;
 
 
void solve() {
    
    string s;
    cin>>s;
    vector<int> mapping(26,0);
    for (int i=0;i<s.length();i++) {
        mapping[s[i]-'A']++;
    }
  
    int num =0;
    for (int i=0; i<26;i++) {
        if (mapping[i]%2) {
            num++;
            if (num==2) {
                cout<<"NO SOLUTION"<<endl;
                return;
            }
        }
    }
    
    int i=0;
    int len =0;
    int tot_len=0;
    while (tot_len< s.length()) {
        if (mapping[i]==0) {
            i++;
            continue;
        }
        if (mapping[i]==1) {
            s[s.length()/2] = 'A'+i;
            tot_len++;
            mapping[i]=0;
            i++;
            continue;
        }
        else {
            s[len] = 'A'+i;
            s[s.length()-1-len] = 'A'+i;
            len+=1;
            tot_len+=2;
            mapping[i] -=2;
        }
    }
    cout<<s<<endl;
      
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