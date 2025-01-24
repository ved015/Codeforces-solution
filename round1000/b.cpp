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

// ll max(ll a, ll b, ll c){ return max(a, max(b, c));}
// ll min(ll a, ll b, ll c){ return min(a, min(b, c));}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll fact(ll a) { return (a <= 1) ? 1 : a * fact(a - 1); }

vll factors(int n) { vll ans; int l = sqrt(n); for (int i = 1; i <= l; i++) { if (n % i == 0){ if (n/i == i) ans.pb(i); else {ans.pb(i); ans.pb(n/i);}}} return ans;}
string DecimalToBinary(ll num){string str; while(num){if(num & 1) str.pb('1');else str.pb('0');num>>=1;}return str;}
ll BinaryToDecimal(string num){ll ans = 0; ll base = 1; for (int i = sz(num) - 1; i >= 0; i--) {if (num[i] == '1') ans += base; base<<=1;}return ans;}

ll helper(vll &temp,vll seg){
    for(int i = 0; i < min(sz(temp),sz(seg)); i++){
        if(temp[i] < seg[i]){
            seg[i] = temp[i];
        }
        else break;
    }
    ll ans = 0;
    for(auto it : seg) ans += it;
    return ans;
}

void Vedant(){
    int n,l,r;
    cin >> n >> l >> r;
    vll a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    l--;
    r--;
    vll left,right,seg;
    for(int i = l; i <= r; i++) seg.pb(a[i]);
    for(int i = 0; i < l; i++) left.pb(a[i]);
    for(int i = r + 1; i < n; i++) right.pb(a[i]);

    sort(all(left));
    sort(all(right));
    sort(all(seg));
    reverse(all(seg));

    cout << min(helper(left,seg),helper(right,seg)) << endl;
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