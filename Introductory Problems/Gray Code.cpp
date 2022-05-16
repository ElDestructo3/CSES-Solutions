#include <bits/stdc++.h>
 
using namespace std;
 
char xor_char(char a, char b) {
    if (a==b) return '0';
    return '1';
}
 
string binaryToGray(string binary) {
    string ans="";
    ans+=binary[0];
    for (int i =1; i<binary.length();i++) {
        ans+=xor_char(binary[i-1],binary[i]);
    }
    return ans;
 
}
 
string intToGray(int num, int n) {
    string ans="";
    if (n==0) {
        for (int i=0;i<n-ans.length();i++) {
            ans+="0";
        }
        return ans;
    }
    while (num) {
        if (num & 1) ans+='1';
        else ans+='0';
        num>>=1;
    }
    reverse(ans.begin(),ans.end());
    string newans="";
    for (int i=0;i<n-ans.length();i++) {
        newans+="0";
    }
    newans+=ans;
    return binaryToGray(newans);
}
 
void solve() {
    
    int n;
    cin>>n;
    long long num = 1LL<<n;
    
    for (int i=0;i<num;i++) {
        string temp = intToGray(i,n);
        //cout<<temp;
        
        cout<<temp<<endl;
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