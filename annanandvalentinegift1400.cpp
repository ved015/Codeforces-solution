#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
pair<int,int> digits(int n){
    vector<int> temp;
    while(n > 0){
        temp.push_back(n%10);
        n = n/10;
    }
    reverse(temp.begin(),temp.end());
    int leadingzero = 0;
    for(int i = temp.size()-1; i >= 1; i--){
        if(temp[i] == 0) leadingzero++;
        else break;
    }
    return make_pair(temp.size(),leadingzero);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> nums(n);
        int digitsum = 0;
        bool flag = false;
        vector<int> zero;
        for(int i = 0; i < n; i++){
            cin >> nums[i];
            // the catch is leading zeroes
            auto it = digits(nums[i]);
            digitsum += it.first;
            if(it.second != 0) zero.push_back(it.second);
        }
        int count = 0;
        sort(zero.begin(),zero.end());
        reverse(zero.begin(),zero.end());
        for(int i = 0; i < zero.size(); i+=2){
            count += zero[i];
        }
        digitsum -= count;
        if(digitsum >= m + 1){
            cout << "Sasha" << endl;
        }
        else{
            cout << "Anna" << endl;
        }
    }
    return 0;
}