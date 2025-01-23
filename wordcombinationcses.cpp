#include<bits/stdc++.h>
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

map<pii, int> dp;

int helper(int idx, int cur_pos, string &s, vector<string> &temp) {
    if (cur_pos == s.size()) return 1;
    if (idx >= temp.size()) return 0;

    pii key = mp(idx, cur_pos);
    if (dp.find(key) != dp.end()) {
        return dp[key];
    }

    int ans = 0;

    if (s.substr(cur_pos, temp[idx].size()) == temp[idx]) {
        ans += helper(idx, cur_pos + temp[idx].size(), s, temp);
    }

    ans += helper(idx + 1, cur_pos, s, temp);

    return dp[key] = ans;
}

void Vedant() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<string> temp(k);
    for (int i = 0; i < k; i++) {
        cin >> temp[i];
    }

    cout << helper(0, 0, s, temp) << "\n";
}


int main(){
    fastio();
    int t = 1;
    while(t--){
       Vedant();
    }
    return 0;
}