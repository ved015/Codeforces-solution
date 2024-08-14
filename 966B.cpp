#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        unordered_map<int,bool> m;
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        bool flag = true;
        m[nums[0]] = true;
        for(int i = 1; i < n; i++){
            if(m.find(nums[i] + 1) == m.end() && m.find(nums[i] - 1) == m.end()){
                flag = false;
                break;
            }
            m[nums[i]] = true;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}