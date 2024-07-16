#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int sum;
        cin >> sum;
        bool flag = false;
        for(int k = 2; k < 1000; k++){
            for(int n = 3; n < 20; n++){
                long long tot = pow(k,n) - 1;
                if(tot > sum*(k-1)) break;
                
                tot = tot/(k-1);
                if(tot == sum){
                    flag = true;
                }
            }
            if(flag) break;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}