#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;
ll nofbits(ll num){
    ll val = 0;
    while(num > 0){
        if(num%2 == 1) val++;
        num = num/2;
    }
    return val;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll a;
        cin >> a;
        ll val = 1;
        ll multi = 2;
        vector<ll> nums;
        while(val <= a){
            nums.push_back(val);
            val = val*multi;
            multi++;
        }
        ll ans = 1e5;
        ll n = nums.size();
        for (ll mask = 0; mask < (1 << n); ++mask) {
            ll sum = 0;
            ll count = 0;
            for (ll i = 0; i < n; ++i){
                if(mask & (1 << i)){
                    sum += nums[i];
                    count++;
                }
            }
            if(sum <= a) ans = min(ans,nofbits(a - sum) + count);
        }
        cout << ans << endl;
    }
    return 0;
}