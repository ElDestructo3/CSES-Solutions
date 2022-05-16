#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    
    long long k;
    cin >> k;
    long long temp = 9;
    
    long long num_len = 1;
    while(true) {
        if (k <= temp*num_len) {
            long long pow_ten = temp/9; 
            long long num = (k-1)/num_len + pow_ten;
            long long num_digit = k - (num-pow_ten)*num_len;
            long long num_digit_back = num_len - num_digit;
            while (num_digit_back) {
                num /= 10;
                num_digit_back--;
            } 
            cout<<num%10<<endl;
            return;
        }
        else {
            k-=temp*num_len;
            num_len++;
            temp*=10;
            
        }
    }
    
    
    
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