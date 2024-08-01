#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for(long long i = 0; i < n; i++){
            cin >> arr[i];
        }
        long long yaseer = 0;
        for(auto &it : arr) yaseer += it;
        long long globalmax = LLONG_MIN;
        long long localmax = 0;
        for(long long i = 1; i<arr.size(); i++){
            localmax = max(arr[i],arr[i]+localmax);
            if(localmax>globalmax) globalmax = localmax;
        }
        localmax = 0;
        for(long long i = 0; i<arr.size() - 1; i++){
            localmax = max(arr[i],arr[i]+localmax);
            if(localmax>globalmax) globalmax = localmax;
        }
        long long adel = globalmax;
        if(yaseer > adel) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}