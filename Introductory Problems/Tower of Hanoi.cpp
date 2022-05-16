#include <bits/stdc++.h>
 
using namespace std;
 
void towerofHanoi(vector<pair<int,int>>& moves, int numDisks, int a, int b, int c) {
    if (numDisks == 1) {
        moves.push_back(make_pair(a,c));
        return;
    }
    towerofHanoi(moves, numDisks-1, a, c, b);
    moves.push_back(make_pair(a,c));
    towerofHanoi(moves, numDisks-1, b, a, c);
}
 
void solve() {
    
    int n;
    cin>>n;
    vector<pair<int,int>>moves;
    int a=1,b=2,c=3;
    towerofHanoi(moves,n,a,b,c);
    cout<<moves.size()<<endl;
    for (auto move:moves) {
        cout<<move.first<<" "<<move.second<<endl;
    }
    
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