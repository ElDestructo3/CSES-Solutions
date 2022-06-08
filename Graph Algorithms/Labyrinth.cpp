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
vector<pair<int,int>> dir = {{1,0}, {0,1}, {0,-1}, {-1,0}};

void solve(int t) {
    int n,m;
    cin >> n >> m;
    int start_x, start_y, end_x, end_y;
    vector<string>grid(n);
    vector<vector<char>>path(n, vector<char>(m));
    vector<vector<bool>>visited(n, vector<bool>(m,false));
    vector<vector<int>>distances(n, vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            visited[i][j] = (grid[i][j] == '#');
            if (grid[i][j] == 'A') {
                start_x = i, start_y = j;
            }
            if (grid[i][j] == 'B') {
                end_x = i, end_y = j;
            }
        }
    }
    queue<pair<int,int>> q;
    visited[start_x][start_y] = true;
    q.push({start_x, start_y});
    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dir[i].first, ny = cur.second + dir[i].second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
                continue;
            }
            if (grid[nx][ny] == '#') {
                continue;
            }
            visited[nx][ny] = true;
            distances[nx][ny] = distances[cur.first][cur.second] + 1;
            if (i == 0) {
                path[nx][ny] = 'D';
            }
            if (i == 1) {
                path[nx][ny] = 'R';
            }
            if (i == 2) {
                path[nx][ny] = 'L';
            }
            if (i == 3) {
                path[nx][ny] = 'U';
            }
            q.push({nx, ny});
        }
    }
    

    if (!visited[end_x][end_y]) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl << distances[end_x][end_y] << endl;
    pair <int,int> cur = {end_x, end_y};
    vector<char> ans(distances[end_x][end_y] + 1);
    for (int dis = distances[end_x][end_y]; dis > 0; dis--) {
        ans[dis] = path[cur.first][cur.second];
        if (ans[dis] == 'D') {
            cur.first--;
        }
        if (ans[dis] == 'R') {
            cur.second--;
        }
        if (ans[dis] == 'L') {
            cur.second++;
        }
        if (ans[dis] == 'U') {
            cur.first++;
        }
    }
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i];
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
    
    
    int t=1;
    //cin>>t;
    
    for (int i =0; i<t;i++){
        
        solve(i);
    }
    
    
    
} 

 
 
