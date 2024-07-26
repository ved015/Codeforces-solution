#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n >> k;
        vector<string> arr(n);
        for(long long i = 0; i < n; i++){
            string s;
            cin >> s;
            arr[i] = s;
        }
        vector<vector<long long> > temp(n,vector<long long>(n));
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                if(arr[i][j] == '1'){
                    temp[i][j] = 1;
                }
                else{
                    temp[i][j] = 0;
                }
            }
        }
        vector<vector<long long> > ans(n/k);
        long long row = 0;
        for(long long i = 0; i < n; i += k){
            for(long long j = 0; j < n; j += k){
                ans[row].push_back(temp[i][j]);
            }
            row++;
        }
        for(long long i = 0; i < ans.size(); i++){
            for(long long j = 0; j < ans[i].size(); j++){
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}