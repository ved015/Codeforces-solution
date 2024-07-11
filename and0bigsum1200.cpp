#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        long long ans = 1;
        int mod = 1e9 + 7;
        for(int i = 1; i <=k; i++){
            ans = (ans*n)%mod;
        }
        cout << ans << endl;
    }
    return 0;
}