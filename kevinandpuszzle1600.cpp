// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<unordered_map>
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

const ll MOD = 998244353;

unordered_map<string, ll> memo;

string getKey(int idx, int liarcnt, bool flag) {
    return to_string(idx) + "," + to_string(liarcnt) + "," + (flag ? "1" : "0");
}

int helper(int idx, int liarcnt, bool flag, vi &a) {
    if (idx >= sz(a)) {
        return 1;
    }

    string key = getKey(idx, liarcnt, flag);
    
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    ll ans = 0;


    if (a[idx] != liarcnt && flag == true) {
        memo[key] = 0;
        return 0;
    }

    if (a[idx] != liarcnt && flag == false) {
        ans += helper(idx + 1, liarcnt + 1, true, a);
        ans %= MOD;
    }

    if (a[idx] == liarcnt && flag == false) {
        ans += helper(idx + 1, liarcnt + 1, true, a);
        ans %= MOD;
        ans += helper(idx + 1, liarcnt, false, a);
        ans %= MOD;
    }

    if (a[idx] == liarcnt && flag == true) {
        ans += helper(idx + 1, liarcnt, false, a);
        ans %= MOD;
    }

    return memo[key] = ans;
}

void Vedant() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    memo.clear();

    ll ans = helper(0, 0, false, a);
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