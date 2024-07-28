#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
void solve(int startx,int starty,int t,set<pair<int,int> >&s,vector<vector<vector<int> > > &dp,int &n){
    if(t == 0){
        if (s.find(make_pair(startx,starty)) == s.end()) {
            s.insert(make_pair(startx,starty));
        }
        return;
    }
    
    int offsetx = startx + n;
    int offsety = starty + n;
    
    if (dp[offsetx][offsety][t] != -1) {
        return;
    }

    if(abs(startx) == abs(starty)){
        solve(startx,starty + 1,t - 1,s,dp,n);
        solve(startx,starty - 1,t - 1,s,dp,n);
        solve(startx + 1,starty,t - 1,s,dp,n);
        solve(startx - 1,starty,t - 1,s,dp,n);
    }
    if(abs(startx) > abs(starty)){
        solve(startx,starty + 1,t - 1,s,dp,n);
        solve(startx,starty - 1,t - 1,s,dp,n);
    }
    if(abs(starty) > abs(startx)){
        solve(startx + 1,starty,t - 1,s,dp,n);
        solve(startx - 1,starty,t - 1,s,dp,n);
    }

    dp[offsetx][offsety][t] = 1;
}
int main(){
    int t;
    cin >> t;
    vector<vector<vector<int> > > dp(2*t + 1,vector<vector<int> >(2*t + 1,vector<int>(t + 1,-1)));
    set<pair<int,int> > s;
    solve(0,0,t,s,dp,t);
    cout << s.size() << endl;
    return 0;
}