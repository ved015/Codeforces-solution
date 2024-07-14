#include<iostream>
#include<vector>
#define ll long long
#include<map>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,x,y;
        cin >> n >> x >> y;
        vector<ll> v(n);
        map <ll,map<ll,ll> > mp;
        for(ll i = 0; i < n; i++){
            cin >> v[i];
        }
        long long ans = 0;
        for(ll i = 0; i < n; i++){
            ans += mp[(x-(v[i]%x))%x][v[i]%y];
            mp[v[i]%x][v[i]%y]++;
        }
        cout << ans << endl;
    }
    return 0;
}