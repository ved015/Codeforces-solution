#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> nums(n);
        for(int i = 0; i <n; i++){
            cin >> nums[i];
        }
        vector<int> bits(31);
        for(int i = 0; i < n; i++){
            int bit = 0;
            while(nums[i] > 0){
                if(nums[i] % 2 == 1){
                    bits[bit]++;
                }
                nums[i] /= 2;
                bit++;
            }
        }
        long long ans = 0;
        for(int i = 30; i >= 0; i--){
            if(n - bits[i] <= k){
                ans += pow(2,i);
                k -= n - bits[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}