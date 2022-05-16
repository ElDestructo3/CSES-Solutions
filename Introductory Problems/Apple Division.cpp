#include <bits/stdc++.h>
 
using namespace std;
 
void addSums(vector<int> arr, vector<long long>&sums, int index, long long sum) {
    if (index == arr.size()) {
        sums.push_back(sum);
        return;
    }
    addSums(arr, sums, index + 1, sum + arr[index]);
    addSums(arr, sums, index + 1, sum);
}
 
void solve() {
    
    int n;
    cin>>n;
    long long totSum=0;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        totSum+=a[i];
    }
        
    vector<long long> sums;
    addSums(a, sums, 0, 0);
    long long diff = LONG_LONG_MAX;
    
    for (auto i:sums) {
        diff = min(diff, abs(totSum - 2 * i));
    }
    cout<<diff<<endl;
 
    
    
    
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