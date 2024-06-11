#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> nums(n);
        for(long long i = 0; i <n; i++) cin >> nums[i];

        vector<long long> ans;
        long long sum = nums[0];
        ans.push_back(sum);
        long long count = 0;
        if(sum%2 != 0) count++;
        long long loss = 0;
        for(long long i = 1; i < n; i++){
            sum += nums[i];
            if(nums[i]%2 != 0) count++;
            loss = (count/3) + (count%3 == 1);
            ans.push_back(sum - loss);
        }

        for(auto it : ans) cout << it << " ";
        cout << endl;
    }
}
