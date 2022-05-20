#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
const int MOD = 1e9 + 7;

struct project {
    int start;
    int finish;
    int profit;
};

bool myfunction (project i,project j) { 
    return (i.finish<j.finish); 
}

int binarySearch(project projects[], int index)
{
    // Initialize 'lo' and 'hi' for Binary Search
    int lo = 0, hi = index - 1;
   
    // Perform binary Search iteratively
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (projects[mid].finish < projects[index].start)  {
            if (projects[mid+1].finish  < projects[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
   
    return -1;
}

void solve() {
    int n;
    cin >> n;
    project projects[n];
    for (int i = 0; i < n; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        projects[i] = {a, b, c};

    }
    sort(projects, projects + n, myfunction);
    vector<int> table(n);
    table[0] = projects[0].profit;
    for (int i = 1; i < n; i++) {
        int include = projects[i].profit;
        int index = binarySearch(projects, i);
        
        if (index != -1) {
            include += table[index];
        }
        table[i] = max(include, table[i-1]);
    }
    cout<<table[n-1]<<endl;
}
    
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    
    int t=1;
    //cin>>t;
    
    while (t--) {
        solve();
    }
    
    
    
} 

 
 
