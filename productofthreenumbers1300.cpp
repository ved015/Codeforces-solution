#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool flag = false;
        int n1,n2,n3;
        for(int i = 2; i<= sqrt(n); i++){
            if(n%i == 0){
                n1 = i;
                int fac1 = i;
                int fac2 = n/i;
                for(int j = 2; j <= sqrt(fac2); j++){
                    n2 = j;
                    n3 = fac2/j;
                    if(fac2%n2 == 0 && n2 != n1 && n3 != n2 && n1 != n3 && n3 >= 2){
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
        }
        if(flag){
            cout << "YES" << endl;
            cout << n1 << " " << n2 << " " << n3 << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}