#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
 
typedef long long ll;
typedef long long ll;
typedef pair<int,int> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<vector<ll> > vvll;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
 
ll max(ll a, ll b, ll c){ return max(a, max(b, c));}
ll min(ll a, ll b, ll c){ return min(a, min(b, c));}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
 
vll factors(int n) { vll ans; int l = sqrt(n); for (int i = 1; i <= l; i++) { if (n % i == 0){ if (n/i == i) ans.pb(i); else {ans.pb(i); ans.pb(n/i);}}} return ans;}
string DecimalToBinary(ll num){string str; while(num){if(num & 1) str.pb('1');else str.pb('0');num>>=1;}return str;}
ll BinaryToDecimal(string num){ll ans = 0; ll base = 1; for (int i = sz(num) - 1; i >= 0; i--) {if (num[i] == '1') ans += base; base<<=1;}return ans;}

void Vedant() {
    int n, x, y;
    cin >> n >> x >> y;
    vi a(n);
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) a[i] = 1;
        if (i % 2 == 0) a[i] = 0;
    }
    if (n % 2 == 1) a[n-1] = 2;
    if (a[x-1] == a[y-1]) {
        if (min(x, y) != 1) {
            if (x < y) a[x-1] = 2;
            else a[y-1] = 2;
        } else {
            a[0] = 2;
            if (n % 2 == 1) a[n-1] = 0;
        }
    }
    for (auto it: a) cout << it << " ";
    cout << endl;

}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        Vedant();
    }
    return 0;
}
