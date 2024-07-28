#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> fr(n),gf(m);
        for(int i = 0; i < n; i++){
            cin >> fr[i];
        }
        for(int i = 0; i < m; i++){
            cin >> gf[i];
        }
        sort(fr.rbegin(),fr.rend());
        long long ans = 0;
        int i = 0,j = 0;
        while(i < n){
            if(j < m){
                if(gf[fr[i] - 1] <= gf[j]){
                    ans += gf[fr[i] - 1];
                }
                else{
                    ans += gf[j];
                    j++;
                }
            }
            else{
                ans += gf[fr[i] - 1];
            }
            i++;
        }
        cout << ans << endl;
    }
    return 0;
}