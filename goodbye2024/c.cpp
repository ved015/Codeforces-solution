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

ll max(ll a, ll b, ll c){ return max(a, max(b, c));}
ll min(ll a, ll b, ll c){ return min(a, min(b, c));}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll fact(ll a) { return (a <= 1) ? 1 : a * fact(a - 1); }

vll factors(int n) { vll ans; int l = sqrt(n); for (int i = 1; i <= l; i++) { if (n % i == 0){ if (n/i == i) ans.pb(i); else {ans.pb(i); ans.pb(n/i);}}} return ans;}
string DecimalToBinary(ll num){string str; while(num){if(num & 1) str.pb('1');else str.pb('0');num>>=1;}return str;}
ll BinaryToDecimal(string num){ll ans = 0; ll base = 1; for (int i = sz(num) - 1; i >= 0; i--) {if (num[i] == '1') ans += base; base<<=1;}return ans;}

map<ll,pair<ll,ll> > dp;
ll k;
 
pair<ll,ll> ans(ll l, ll r) {
    ll L = r-l+1;
 
    if(l > r) throw 1;
 
    if(L < k) return mp(0,0);
 
    if(dp.find(L) != dp.end()) {
        return mp(dp[L].first + (l-1) * dp[L].second, dp[L].second);
    }
 
    if(L & 1) {
        if(L != 1){
        auto a = ans(l,l+ L/2-1);
        auto b = ans(l+L/2 + 1, r);
        pair<ll,ll> lr = mp(a.first + b.first +l +  L/2, a.second + b.second + 1);
        dp[L] = mp(lr.first - lr.second * (l-1),lr.second);
        return lr;
        }
        else{
            dp[1] = mp(1,1);
            return mp(l, 1);
        }
    }
    else{
        auto a = ans(l,l+ L/2-1);
        auto b = ans(l+L/2, r);
        pair<ll,ll> lr = mp(a.first + b.first,a.second + b.second);
        dp[L] = mp(lr.first - lr.second * (l-1), lr.second);
        return lr;
    }
}
 
void Vedant(){
    ll n;
    cin >> n >> k;
    dp.clear();
    cout << ans(1,n).first << endl;
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