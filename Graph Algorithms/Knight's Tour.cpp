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
vector<pair<int,int>> knight_dirs = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
int MAXN = 3e5 + 5;
vector<vector<int>>adjList(MAXN), reverseAdjList(MAXN), condensedReverseAdjList(MAXN);
vector<bool> visited(MAXN, false);
vector<int> path, comp(MAXN, -1), compValues(MAXN, 0), dp(MAXN, 0);
unordered_map<string, int> visited_strings;
string ans;

void dfs(int u) {
    while (adjList[u].size()) {
        int v = adjList[u].back();
        adjList[u].pop_back();
        dfs(v);
    }
    path.push_back(u);

}

int degree_vertex(int x, int y, vector<vector<int>>& knight_moves) {
    int degree = 0;
    for (int i = 0; i < 8; i++) {
        int new_x = x + knight_dirs[i].first;
        int new_y = y + knight_dirs[i].second;
        if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8 && !knight_moves[new_x][new_y]) {
            degree++;
        }
    }
    return degree;
}


bool backtrack(int move_number, int x, int y, vector<vector<int>>& knight_moves) {

    knight_moves[x][y] = move_number;
    if (move_number == 64) return true;
    vector<tuple<int,int,int>> moves;
    for (int i = 0; i < 8; i++) {
        int new_x = x + knight_dirs[i].first;
        int new_y = y + knight_dirs[i].second;
        if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8 && !knight_moves[new_x][new_y]) {
            int d = degree_vertex(new_x, new_y, knight_moves);
            moves.push_back({d, new_x, new_y});
        }
    }

    sort(moves.begin(), moves.end());
    for (auto [d, possible_x, possible_y] : moves) {
        //if 
        if (backtrack(move_number + 1, possible_x, possible_y, knight_moves)) return true;
    }
    knight_moves[x][y] = 0;
    return false;
}


void solve(int t) {
    
    int start_x, start_y;
    cin >> start_y >> start_x;
    start_x--;
    start_y--;
    vector<vector<int>> knight_moves(8, vector<int>(8, 0));

    backtrack(1, start_x, start_y, knight_moves);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << knight_moves[i][j] << " ";
        }
        cout << endl;
    }
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
    
    for (int i = 0; i < t; i++){
        
        solve(i + 1);
    }

}