// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<vector<ll> > vvll;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll fact(ll a) { return (a <= 1) ? 1 : a * fact(a - 1); }

vll factors(int n) { vll ans; int l = sqrt(n); for (int i = 1; i <= l; i++) { if (n % i == 0){ if (n/i == i) ans.pb(i); else {ans.pb(i); ans.pb(n/i);}}} return ans;}
string DecimalToBinary(ll num){string str; while(num){if(num & 1) str.pb('1');else str.pb('0');num>>=1;}return str;}
ll BinaryToDecimal(string num){ll ans = 0; ll base = 1; for (int i = sz(num) - 1; i >= 0; i--) {if (num[i] == '1') ans += base; base<<=1;}return ans;}

void Vedant(){
    ll n;
    cin >> n;
    vll a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    map<ll,ll> freq;
    for(auto &it : a) freq[it]++;

    ll cnt = 0;
    for(auto it : freq){
        if(it.second >= 2) cnt++;
    }
    
    if(cnt == 0){
        cout << -1 << endl;
        return;
    }
    // ans will be yes we will get a square or a rectangle
    if(cnt >= 2){
        vll ans;
        for(auto &it : freq){
            if(it.second >= 2) ans.pb(it.first);
            if(sz(ans) >= 2) break;
        }
        cout << ans[0] << " " << ans[0] << " " << ans[1] << " " << ans[1] << endl;
        return;
    }

    ll val = -1;
    for(auto it : freq){
        if(it.second >= 2) val = it.first;
    }

    vll temp;
    for(auto it : freq){
        if(it.first != val) temp.pb(it.first);
    }
    // if val  comes more than 2 times
    ll rem = freq[val] - 2;
    for(ll i = 0; i < rem; i++) temp.pb(val);

    sort(all(temp));
    for(ll i = 0; i < sz(temp) - 1; i++){
        if(abs(temp[i+1] - temp[i]) < 2*val){
            cout << val << " " << val << " " << temp[i] << " " << temp[i+1] << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
}


int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
       Vedant();
    }
    return 0;
}