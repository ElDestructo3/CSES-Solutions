#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
 
void solve() {
    int n,k;
    cin>>n>>k;
    set<pair<int,int>>leftSet, rightSet;
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    if (k==1) {
        for (int i=0;i<n;i++) {
            cout<<"0 ";
        }
        return;
    }
    if (k==2) {
        for (int i=0;i<n-1;i++) {
            cout<<abs(arr[i]-arr[i+1])<<" ";
        }
        return;
    }
    vector<pair<int,int>> window;
    for (int i=0;i<k;i++) {
      
        window.push_back(make_pair(arr[i],i));
    }
    sort(window.begin(),window.end());
    int leftSum=0, rightSum=0;
    for (int i=0 ;i<k/2 + k%2; i++) {
        leftSet.insert(window[i]);
        leftSum+=window[i].first;
    }
    for (int i=k/2 + k%2;i<k; i++) {
        rightSet.insert(window[i]);
        rightSum+=window[i].first;
    }
 
    
    int median = leftSet.rbegin()->first;
    cout<<median*leftSet.size()-leftSum + rightSum - rightSet.size()*median<<" ";
    for (int i=1; i<n-k+1;i++) {
        if (leftSet.count({arr[i-1],i-1})) {
            leftSet.erase({arr[i-1],i-1});
            leftSum-=arr[i-1];
        }
        else {
            rightSet.erase({arr[i-1],i-1});
            rightSum-=arr[i-1];
 
        }
        if (*(leftSet.rbegin())<make_pair(arr[k-1+i],k-1+i) ) {
            rightSet.insert({arr[k-1+i],k-1+i});
            rightSum+=arr[k-1+i];   
        }
        else {
            leftSet.insert({arr[k-1+i],k-1+i});
            leftSum+=arr[k-1+i];   
        }
        while (leftSet.size() < k/2 + k%2) {
            pair<int,int> temp = (*rightSet.begin());
            rightSet.erase(temp);
            leftSet.insert(temp);
            leftSum+=temp.first;
            rightSum-=temp.first;
        }
        while (leftSet.size() > k/2 + k%2) {
            pair<int,int> temp = (*leftSet.rbegin());
            leftSet.erase(temp);
            rightSet.insert(temp);
            rightSum+=temp.first;
            leftSum-=temp.first;
        }
        median = leftSet.rbegin()->first;
        cout<<median*leftSet.size()-leftSum + rightSum - rightSet.size()*median<<" ";
    }
    cout<<endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long t=1;
    //cin>>t;
  
    while (t--) {
        solve();
    }
    
    
}