#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_map>
#include<map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        map<int,vector<int> > num;
        for(int i = 0; i < n; i++){
            cin >> nums[i];
            num[nums[i]].push_back(i);
        }
        int m;
        cin >> m;
        vector<string> pairs(m);
        for(int i = 0; i < m; i++){
            cin >> pairs[i];
        }
        for(auto &it : pairs){
            map<char,vector<int> > ch;
            map<char,int> mapping;
            string temp = it;
            int val = temp.size();
            if(val != n){
                cout << "NO" << endl;
                continue;
            }
            for(int i = 0; i < n; i++){
                mapping[temp[i]] = nums[i];
                ch[temp[i]].push_back(i);
            }
            bool flag = true;
            for(auto it : mapping){
                if(ch[it.first] != num[it.second]){
                    flag = false;
                    break; 
                }
            }
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }

    }
    return 0;
}