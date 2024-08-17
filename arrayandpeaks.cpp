#include<iostream>
#include<map>
#include<algorithm>
// #include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(n == 1 && k == 1){
            cout << - 1 << endl;
            continue;
        }
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            nums[i] = i + 1;
        }
        if(k == 0){
            for(auto it : nums){
                cout << it << " ";
            }
            cout << endl;
            continue;
        }
        int count = 0;
        bool flag = false;
        for(int i = 1; i < n - 1; i+=2){
            count++;
            swap(nums[i],nums[i+1]);
            if(count == k){
                flag = true;
                break;
            }
        }
        if(flag){
            for(auto it : nums){
                cout << it << " ";
            }
            cout << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}