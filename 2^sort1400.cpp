#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        vector<ll> nums(n);
        for(ll i = 0; i < n ; i++){
            cin >> nums[i];
        }
        ll l = 0,r = 1;
        ll ans = 0;
        while(r < n){
            while(r < n && nums[r]*2 > nums[r-1]){
                r++;
            }
            // len = (r - l + 1) - k;
            if(r - l > k) ans += (r - l) - k;
            l = r;
            r++;
        }
        cout << ans << endl;
    }
    return 0;
}