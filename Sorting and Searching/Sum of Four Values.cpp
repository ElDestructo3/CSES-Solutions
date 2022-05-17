#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
 
bool check(int time, int products, vector<int> arr) {
    int num=0;
    for (int i=0;i<arr.size();i++) {
        num+=time/arr[i];
        if (num>=products) return true;
    }
    
    return false;
}
 
void solve() {
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>times(n);
    
    for(int i=0;i<n;i++) {
        cin>>times[i].first;
        times[i].second = i;
        
    }
    
    vector<tuple<int,int,int>>sums;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            sums.push_back(make_tuple(times[i].first+times[j].first,times[i].second,times[j].second));
        }
    }
    
    sort(sums.begin(),sums.end());
    int left=0, right=sums.size()-1;
    //print sums
    //for (int i=0;i<sums.size();i++) {
    //   cout<<get<0>(sums[i])<<" "<<get<1>(sums[i])<<" "<<get<2>(sums[i])<<endl;
    //}
    
    while (left<right) {
        int sum = get<0>(sums[left])+get<0>(sums[right]);
        if (sum==x) {
            set<int>temp;
            temp.insert(get<1>(sums[left]));
            temp.insert(get<2>(sums[left]));
            temp.insert(get<1>(sums[right]));
            temp.insert(get<2>(sums[right]));
            if (temp.size()==4) {
                cout<<get<1>(sums[left])+1<<" "<<get<1>(sums[right])+1<<" "<<get<2>(sums[left])+1<<" "<<get<2>(sums[right])+1<<endl;
                return;
            }
            else {
                right--;
            }
        }
        else if (sum<x) left++;
        else right--;
    }
    cout<<"IMPOSSIBLE"<<endl;
    
    
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