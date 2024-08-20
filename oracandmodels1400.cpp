#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll> dp;
ll solve(int idx,vector<ll> &nums) {
    int n = nums.size();

    if(dp[idx] != -1){
        return dp[idx];
    }

    ll ans = 0;
    for(int i = 2*(idx + 1); i <= n; i = i + (idx + 1)){
        if(nums[i - 1] > nums[idx]){
            ans = max(ans,1 + solve(i - 1,nums));
        }
    }
    return dp[idx] = ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        dp.assign(n,-1);
        ll maxi = 1;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, 1 + solve(i,nums));
        }
        cout << maxi << endl;
    }
    return 0;
}
