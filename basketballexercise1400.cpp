#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

ll helper(ll idx,ll prev,vector<vector<ll> >&height,vector<vector<ll> > &dp){

    if(idx >= height[0].size()) return 0;

    if(dp[prev][idx] != -1) return dp[prev][idx];

    ll take = 0;
    if(prev == 0) take = height[1][idx] + helper(idx + 1,1,height,dp);
    else take = height[0][idx] + helper(idx + 1,0,height,dp);

    ll nottake = helper(idx + 1,prev,height,dp);

    return dp[prev][idx] = max(take,nottake);
}
int main(){
    ll n;
    cin >> n;
    vector<vector<ll> > height(2,vector<ll>(n));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin >> height[i][j];
        }
    }
    vector<vector<ll > > dp1(2,vector<ll>(n,-1)),dp2(2,vector<ll>(n,-1));
    ll val1 = helper(0,0,height,dp1);
    ll val2 = helper(0,1,height,dp2);
    cout << max(val1,val2) << endl;
    return 0;
}