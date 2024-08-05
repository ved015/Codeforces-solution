// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
// #include<bits/stdc++.h>
#include<queue>
#include<vector>
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> nums(n);
        priority_queue<long long> odd;
        priority_queue <long long, vector<long long>, greater<long long> > even;
        for(long long i = 0; i < n; i++){
            cin >> nums[i];
            if(nums[i] & 1) odd.push(nums[i]);
            else even.push(nums[i]);
        }
        if(odd.empty() || even.empty()){
            cout << 0 << endl;
            continue;
        }
        long long ans = 0;
        while(true){
            if(even.empty()) break;
            ans++;
            long long oddval = odd.top();
            long long evenval = even.top();
            even.pop();
            if(oddval > evenval){
                odd.push(oddval + evenval);
            }
            else{
                odd.push(evenval + oddval);
                even.push(evenval);
            }
        }
        cout << ans << endl;
    }
}