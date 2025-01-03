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

void Vedant(){
    ll n,m,L;
    cin >> n >> m >> L;
    vector<pair<ll,ll> > a(n),b(m);
    for(int i = 0; i < n; i++){
        ll l,r;
        cin >> l >> r;
        a[i] = mp(l,r);
    }
    for(int i = 0; i < m; i++){
        ll x,v;
        cin >> x >> v;
        b[i] = mp(x,v);
    }
    priority_queue<ll> pq;
    ll j = 0;
    ll power = 1;
    ll ans = 0;
    for(int i = 0; i < n; i++){

        ll l = a[i].first;
        ll r = a[i].second;
        ll d = r - l + 2;
        if(L <= l) break;

        while(j < m){
            if(b[j].first < l) pq.push(b[j].second);
            else break;
            j++;
        }

        if(power >= d){
            power = power;
        }
        else{
            while(!pq.empty() && power < d){
                power += pq.top();
                pq.pop();
                ans++;
            }
        }

        if(power < d){
            cout << - 1 << endl;
            return;
        }
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