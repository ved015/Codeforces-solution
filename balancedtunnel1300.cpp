#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> entry(n),exit(n);
    map<int,bool> m;
    for(int i = 0; i < n; i++){
        cin >> entry[i];
        m[entry[i]] = false;
    }
    for(int i = 0; i < n; i++){
        cin >> exit[i];
    }
    int i = 0,j = 0;
    int ans = 0;
    while(i < n){
        if(m[entry[i]] == false){
            if(entry[i] == exit[j]){
                i++;
                j++;
            }
            else{
                while(j < n && entry[i] != exit[j]){
                    ans++;
                    m[exit[j]] = true;
                    j++;
                }
            }
        }
        else i++;
    }
    cout << ans << endl;
}