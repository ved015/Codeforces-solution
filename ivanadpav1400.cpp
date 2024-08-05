#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int solve(int l,int k,vector<int> &nums){
    int addres = nums[l];
    int maxi = INT_MIN;
    for(int i = l; i < nums.size(); i++){
        addres = addres & nums[i];
        if(addres >= k){
            maxi = max(maxi,i);
        }
    }
    return maxi;
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
        int q;
        cin >> q;
        vector<int> ans;
        for(int i = 0; i < q; i++){
            int l,k;
            cin >> l >> k;
            int val = solve(l - 1,k,nums);
            if(val == INT_MIN) ans.push_back(-1);
            else ans.push_back(val + 1);
        }
        for(auto &it : ans){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}