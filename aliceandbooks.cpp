#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        if(nums[n-1] == temp[n-1] || nums[n-1] == temp[n-2]){
            cout <<  temp[n-1] + temp[n-2] << endl;
        }
        else cout << temp[n-1] + nums[n-1] << endl;
    }
    return 0;
}