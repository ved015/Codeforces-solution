#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;
int helper(int idx,vector<int> &nums,vector<int> &dp){
    int n = nums.size();
    if(idx >= n) return 0;
    if(dp[idx] != -1) return dp[idx];
    // remove requires one operation
    int remove = 1 + helper(idx + 1,nums,dp);

    // not remove
    int notremove = INT_MAX;
    if(idx + nums[idx] < n) notremove = helper(idx + nums[idx] + 1,nums,dp);

    return dp[idx] = min(remove,notremove);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        vector<int> dp(n,-1);
        cout << helper(0,nums,dp) << endl;
    }
    return 0;
}
