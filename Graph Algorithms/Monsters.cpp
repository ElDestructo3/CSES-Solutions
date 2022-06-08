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

void solution(int x, int y, int start_x, int start_y, vector<vector<char>>& path, vector<vector<int>>& distancePerson) {

    cout<<"YES"<<endl;
    int len = distancePerson[x][y];
    cout<<len<<endl;
    vector<char>ans(len);
    for (int i = len-1; i >=0; i--) {
        ans[i] = path[x][y];
        if (ans[i] == 'D') x--;
        if (ans[i] == 'R') y--;
        if (ans[i] == 'U') x++;
        if (ans[i] == 'L') y++;
    }
    for (int i = 0; i < len; i++) {
        cout<<ans[i];
    }
    cout<<endl;
}

void solve(int t) {
    int n,m;
    cin >> n >> m;
    int start_x, start_y;
    queue<pair<int,int>> monsters;
    vector<string> grid(n);
    vector<vector<int>>distanceMonsters(n, vector<int>(m,0));
    vector<vector<int>>distancePerson(n, vector<int>(m,0));
    vector<vector<bool>>visited(n, vector<bool>(m,false));
    vector<vector<char>> path(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        cin >> grid[i]; 
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start_x = i, start_y = j;
            }
            if (grid[i][j] == 'M') {
                visited[i][j] = true;
                monsters.push({i,j});
            }
            if (grid[i][j] == '#') {
                visited[i][j] = true;
            }
        }
    }
    while (!monsters.empty()) {
        auto vertex = monsters.front();
        monsters.pop();
        for (int i = 0; i < 4; i++) {
            int x = vertex.first + dir[i].first;
            int y = vertex.second + dir[i].second;
            if (x>=0 && x <n && y>=0 && y < m && !visited[x][y]) {
                visited[x][y] = true;
                distanceMonsters[x][y] = distanceMonsters[vertex.first][vertex.second] + 1;
                monsters.push({x,y});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) distanceMonsters[i][j] = INT_MAX;
            visited[i][j] = (grid[i][j] == '#');
            
        }
    }
    
    queue<pair<int,int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    while (!q.empty()) {
        auto vertex = q.front(); 
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = vertex.first + dir[i].first;
            int y = vertex.second + dir[i].second;
            if (x>=0 && x <n && y>=0 && y < m && !visited[x][y] && distancePerson[vertex.first][vertex.second] + 1 < distanceMonsters[x][y]) {
                if (i == 0) {
                    path[x][y] = 'D';
                }
                if (i == 1) {
                    path[x][y] = 'R';
                }
                if (i == 2) {
                    path[x][y] = 'L';
                }
                if (i == 3) {
                    path[x][y] = 'U';
                }

                visited[x][y] = true;
                distancePerson[x][y] = distancePerson[vertex.first][vertex.second] + 1;
                q.push({x,y});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (grid[i][0] != '#' && grid[i][0] != 'M' && visited[i][0]) {
            solution(i,0,start_x,start_y,path,distancePerson);
            return;
        }
        if (grid[i][m-1] != '#' && grid[i][m-1] != 'M' && visited[i][m-1]) {
            solution(i,m-1,start_x,start_y,path,distancePerson);
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        if (grid[0][i] != '#' && grid[0][i] != 'M' && visited[0][i]) {
            solution(0,i,start_x,start_y,path,distancePerson);
            return;
        }
        if (grid[n-1][i] != '#' && grid[n-1][i] != 'M' && visited[n-1][i]) {
            solution(n-1,i,start_x,start_y,path,distancePerson);
            return;
        }
    }
    cout<<"NO"<<endl;
   
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

 
 
