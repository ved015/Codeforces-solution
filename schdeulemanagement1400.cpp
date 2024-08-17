#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
bool ispossible(ll t, map<ll, ll> &mp) {
    ll add = 0, rem = 0;
    for(auto it : mp) {
        if(it.second < t) {
            // he can contribute hese rem hours to these tasks
            add += (t - it.second) / 2;
        } else if(it.second > t) {
            // his remaining task need to be completed by other
            rem += (it.second - t);
        }
    }
    return add >= rem;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
        map<ll,ll> mp;
        // for those people whose are ideal for whole m
        for(ll i = 1; i <= n; i++){
            mp[i] = 0;
        }

        for(ll i = 0; i < m; i++){
            ll a;
            cin >> a;
            mp[a]++;
        }
        // 1 worker proficient 2 task = 1 task of non proficient
        ll l = 0,r = m;
        ll result = -1;
        while(l <= r){
            ll mid = l + (r-l)/2;
            if(ispossible(mid,mp)){
                result = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << result << endl;
    }
}