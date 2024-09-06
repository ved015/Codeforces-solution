#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        map<int,int> m;
        for(int i = 0; i < n; i++){
            cin >> nums[i];
            m[nums[i]]++;
        }
        vector<int> dist;
        for(int i = 0; i < n; i++){
            int mini = INT_MAX;
            for(int j = 0; j < n; j++){
                if(j != i){
                    mini = min(mini,abs(nums[j]-nums[i]));
                }
            }
            dist.push_back(mini);
        }
        int ans = 0;
        for(int no = 1; no <= 250; no++){
            bool flag = true;
            if(m.find(no) != m.end()) continue;
            for(int i = 0; i < n; i++){
                if(abs(no-nums[i]) > dist[i]) flag = false;
            }
            if(flag){
                ans = 1;
                break;
            }
        }
        if(ans == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}