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

vll factors(ll n) { vll ans; ll l = sqrt(n); for (ll i = 1; i <= l; i++) { if (n % i == 0){ if (n/i == i) ans.pb(i); else {ans.pb(i); ans.pb(n/i);}}} return ans;}
string DecimalToBinary(ll num){string str; while(num){if(num & 1) str.pb('1');else str.pb('0');num>>=1;}return str;}
ll BinaryToDecimal(string num){ll ans = 0; ll base = 1; for (int i = sz(num) - 1; i >= 0; i--) {if (num[i] == '1') ans += base; base<<=1;}return ans;}

const int mod = 998244353;
vector<vll> dp;
ll helper(ll idx, ll val, vll &a){
    if(idx >= sz(a)) return 0;

    if(dp[idx][val] != -1) return dp[idx][val];

    ll take, nottake;
    if(a[idx] == val){
        if(val == 1){
            take = helper(idx + 1, 2, a) % mod;
            nottake = helper(idx + 1, 1, a) % mod;
        }
        else if(val == 2){
            take = (helper(idx + 1, 3, a) + helper(idx + 1, 2, a)) % mod;
            nottake = helper(idx + 1, 2, a) % mod;
        }
        else{
            take = 1; // 1 returned
            nottake = helper(idx + 1, 3, a) % mod;
        }
    }
    else return dp[idx][val] = helper(idx + 1, val, a) % mod;

    return dp[idx][val] = (take + nottake) % mod;
}

void Vedant(){
    ll n;
    cin >> n;
    vll a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    dp.assign(n, vector<ll>(4, -1));
    cout << helper(0, 1, a) << endl;
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
