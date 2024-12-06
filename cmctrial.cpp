#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solv e(vector <long long> &nums,int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] > 1 && i > 0){
            while(nums[i] < nums[i-1]){
                nums[i] *= nums[i];
                ans++;
            }
        }
        if(nums[i] == 1 && i > 0){
            if(nums[i-1] > nums[i]) return -1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--){
       int n;
       cin >> n;
       vector<long long>nums(n);
       for(int i=0; i<n; i++){
           cin >> nums[i];
       }
       cout << solve(nums,n) << endl;
    }

    return 0;
}