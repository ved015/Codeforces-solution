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
ll fact(ll a) { return (a <= 1) ? 1 : a * fact(a - 1); }

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

void Vedant(){
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> v;
    string s;
    cin >> s;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    ll mx = 0;
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            mx = max(mx + v[i], v[i]);
            res = max(res, mx);
        }
        else
        {
            mx = 0;
        }
    }
    if (res > k)
    {
        cout << "NO" << endl;
    }
    else if (res == k)
    {
        cout << "YES" << endl;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                v[i] = -1e18;
            }
        }
        for(auto &it : v) cout << it << " ";
        cout << endl;
    }
    else
    {
        ll zer = -1;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                zer = i;
                break;
            }
        }
        if (zer == -1)
        {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        ll pref = 0;
        ll psum = 0;
        ll ssum = 0;
        for (int i = zer - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                break;
            }
            else
            {
                psum += v[i];
                pref = max(psum, pref);
            }
        }
 
        ll suff = 0;
        for (int i = zer + 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                break;
            }
            else
            {
                ssum += v[i];
                suff = max(ssum, suff);
            }
        }
        v[zer] = k - pref - suff;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0' && i != zer)
            {
                v[i] = -1e18;
            }
        }
        for(auto &it : v) cout << it << " ";
        cout << endl;
    }
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