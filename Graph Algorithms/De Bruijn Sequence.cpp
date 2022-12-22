#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
vector<pair<int,int>> dir = {{1,0}, {0,1}, {0,-1}, {-1,0}};
int MAXN = 3e5 + 5;
vector<vector<pair<int,int>>>adjList(MAXN), reverseAdjList(MAXN), condensedReverseAdjList(MAXN);
vector<bool> visited(MAXN, false);
vector<int> topological_order, comp(MAXN, -1), compValues(MAXN, 0), dp(MAXN, 0);
unordered_map<string, int> visited_strings;
string ans;

void dfs(string node) {
    string str1 = node + "0";
    string str2 = node + "1";
    if (visited_strings.find(str1) == visited_strings.end()) {
        visited_strings[str1] = 1;
        dfs(str1.substr(1));
        ans += '0';
    }
    if (visited_strings.find(str2) == visited_strings.end()) {
        visited_strings[str2] = 1;
        dfs(str2.substr(1));  //00 with 1 added makes last two chars 01, so check for substr excluding first char
        ans += '1';
    }
}




void solve(int t) {
    
    int n;
    cin >> n;

    string start_string = string(n - 1, '0');
    dfs(start_string);
    ans += start_string;
    cout << ans;

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
    
    for (int i =0; i<t;i++){
        
        solve(i + 1);
    }

}