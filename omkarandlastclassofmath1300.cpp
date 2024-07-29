#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2 == 0) cout << n/2 << " " << n/2 << endl;
        else{
            int idx = 0;
            for(int i = 3; i <= sqrt(n); i+=2){
                if(n%i == 0){
                    idx = i;
                    break;
                }
            }
            if(idx == 0) idx = n;
            cout << n/idx << " " << (n/idx)*(idx-1) << endl;
        }
    }
    return 0;
}