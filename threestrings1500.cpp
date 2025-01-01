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

vector<vector<int> > dp;

int helper(int i, int j, string &a, string &b, string &c) {
    int n = sz(a);
    int m = sz(b);
    if (i + j >= n + m) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int take1 = INT_MAX, take2 = INT_MAX;

    if (i < n && c[i + j] == a[i]) {
        take1 = helper(i + 1, j, a, b, c);
    } else if (i < n) {
        take1 = 1 + helper(i + 1, j, a, b, c);
    }

    if (j < m && c[i + j] == b[j]) {
        take2 = helper(i, j + 1, a, b, c);
    } else if (j < m) {
        take2 = 1 + helper(i, j + 1, a, b, c);
    }

    return dp[i][j] = min(take1, take2);
}

void Vedant(){
    string a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;
    int n = sz(a);
    int m = sz(b);
    dp.assign(n + 1,vector<int>(m + 1,-1));
    cout << helper(0,0,a,b,c) << endl;
}
// ab
// ba
// aabb
// helper(1,0) -> 2                1 + helper(0,1) -> 2
// 1 + helper(2,0)                 helper(0,2)
// helper(2,1)                     1 + helper(1,2)
// 1 + helper(2,2)                 helper(2,2) 

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
       Vedant();
    }
    return 0;
}