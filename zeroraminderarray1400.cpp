#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        map<ll,ll> mp;
        for(ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            if(a%k != 0) mp[a%k]++;
        }
        if(mp.size() == 0){
            cout << 0 << endl;
            continue;
        }
        ll maxi = LLONG_MIN;
        for(auto it : mp){
            maxi = max(it.second,maxi);
        }
        ll idx = LLONG_MAX;
        for(auto it : mp){
            if(it.second == maxi){
                idx = min(it.first,idx);
            }
        }
        cout << (maxi - 1)*k + (k - idx) + 1 << endl;
    }
    return 0;
}