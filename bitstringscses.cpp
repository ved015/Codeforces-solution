#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define endl "\n"
#define all(x) (x).begin(), (x).end()
 
const ld pi = acos(-1);
const ll MOD = 1000000007;
const ll N = 1e5 + 7;
 
typedef vector<long long> vll;
#define pb push_back
#define sz(x) ((int)(x).size())
 

ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

 
signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
 
    ll n;
    cin >> n;
 
    cout << powermod(2, n, MOD) % MOD;
 
    return 0;
}