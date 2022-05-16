#include <bits/stdc++.h>
 
using namespace std;
 
bool isSafe(vector<string> board, int row, int col) {
    int i,j;
    if (board[row][col]=='*') return false;
    for (i=0;i<col;i++) {
        if (board[row][i]=='Q') return false;
    }
    for (i=row, j=col; i>=0 && j>=0; i--, j--) {
        if (board[i][j]=='Q') return false;
    }
    for (i=row, j=col; j>=0 && i<8; i++, j--) {
        if (board[i][j]=='Q') return false;
    }
    return true;
}
 
void solveQueens(vector<string>board, int col, long long& sum) {
    if (col == 8) {
        sum++;
        return;
    }
    for (int i=0; i<8;i++) {
        if (isSafe(board, i, col)) {
            board[i][col]='Q';
            solveQueens(board, col+1, sum);
            board[i][col]='.';
        }
    }
}
 
void solve() {
    
    vector<string> board(8);
    for (int i = 0;i < 8; i++) {
        cin>>board[i];
    }
    long long sum = 0;  
 
    solveQueens(board, 0, sum);
    cout<<sum<<endl;
    
    
    
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