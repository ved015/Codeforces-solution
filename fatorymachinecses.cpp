#include <bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;

bool check(ll val,vector<ll> &a,ll t){
    ll prod = 0;
    for(auto it : a){
        prod += val/it;
        if(prod >= t) return true;
    }
    if(prod >= t) return true;
    return false;
}
int main() {
    ll n,t;
    cin >> n >> t;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(),a.end());
    
    ll s = 0,e = 1e18;
    ll res = -1;
    while(s <= e){
        ll mid = s + (e-s)/2;
        if(check(mid,a,t)){
            res = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }
    
    cout << res << endl;
    return 0;
}
