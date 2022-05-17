#include <bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve() {
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>arr(n);
    for (int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        arr[i] = make_pair(temp,i+1);
    }
    sort(arr.begin(),arr.end());
    int left = 0, right = n-1;
    while(left<right) {
        int temp_sum = arr[left].first + arr[right].first;
        if (temp_sum==x) {
            cout<<arr[left].second<<" "<<arr[right].second<<endl;
            return;
        }
        else if (temp_sum>x) {
            right--;
        }
        else {
            left++;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
   
}
 
signed main() {
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