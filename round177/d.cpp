// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cmath>
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

ll gcd(ll a, ll b) {if (b > a) return gcd(b, a); if (b == 0) return a; return gcd(b, a % b);}
// ll fact(ll a) { return (a <= 1) ? 1 : a * fact(a - 1); }

vll factors(int n) { vll ans; int l = sqrt(n); for (int i = 1; i <= l; i++) { if (n % i == 0){ if (n/i == i) ans.pb(i); else {ans.pb(i); ans.pb(n/i);}}} return ans;}
string DecimalToBinary(ll num){ string str; while(num){ if(num & 1) str.pb('1'); else str.pb('0'); num >>= 1; } return str; }
ll BinaryToDecimal(string num){ ll ans = 0; ll base = 1; for (int i = sz(num) - 1; i >= 0; i--) { if (num[i] == '1') ans += base; base <<= 1; } return ans; }

long long pow(long long x,long long n){
    long long ans = 1;
    while(n > 0){
        if(n & 1){
            ans = ans * x;
            n--;
        }
        else{
            x = x * x;
            n = n / 2;
        }
    }
    return ans;
}

ll MOD = 998244353;

vector<vector<ll> > dp;
ll helper(int idx,int sum,vll &c){

    if(idx == (int)c.size() || sum == 0){
        if(sum == 0) return 1;
        return 0;
    }

    if(dp[idx][sum] != -1) return dp[idx][sum];

    // assign odd
    ll take = 0;
    if(sum >= c[idx] && c[idx] > 0) take = helper(idx + 1,sum - c[idx],c);

    // assign not odd
    ll nottake = helper(idx + 1,sum,c);

    return dp[idx][sum] = (take + nottake)%MOD;
}

ll fact(ll x){
	ll res = 1;
	for (ll i = 1; i <= x; i++){
		res = (res * i) % MOD;
	}
	return res;
}

ll bpow(ll x, ll p){
	ll res = 1;
	while(p){
		if (p % 2){
			res = (res * x) % MOD;
		}
		p >>= 1;
		x = (x * x) % MOD;
	}
	return res;
}

void Vedant(){
    vll c(26);
    for(auto &it : c) cin >> it;

    ll sum = 0;
    for(auto &it : c) sum += it;


    dp.assign(c.size(), vector<ll>((sum/2) + 1, -1));
    ll ways = helper(0,sum/2,c);

    ll ans = ways * fact(sum / 2) % MOD * fact((sum + 1) / 2) % MOD;
	for (int i = 0; i < 26; i++){
		ans = (ans * bpow(fact(c[i]), MOD - 2)) % MOD;
	}
 
	cout << ans << endl;

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