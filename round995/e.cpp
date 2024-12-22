// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;

typedef long long ll;
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

ll max(ll a, ll b, ll c){ return max(a, max(b, c));}
ll min(ll a, ll b, ll c){ return min(a, min(b, c));}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll fact(ll a) { return (a <= 1) ? 1 : a * fact(a - 1); }

vll factors(int n) { vll ans; int l = sqrt(n); for (int i = 1; i <= l; i++) { if (n % i == 0){ if (n/i == i) ans.pb(i); else {ans.pb(i); ans.pb(n/i);}}} return ans;}
string DecimalToBinary(ll num){string str; while(num){if(num & 1) str.pb('1');else str.pb('0');num>>=1;}return str;}
ll BinaryToDecimal(string num){ll ans = 0; ll base = 1; for (int i = sz(num) - 1; i >= 0; i--) {if (num[i] == '1') ans += base; base<<=1;}return ans;}


ll solve(ll cost, const vector<pair<ll,ll> > &temp, ll k) {
    ll customer = 0;
    ll negatives = 0;

    for (const auto &p : temp) {
        if (p.first >= cost) {
            customer++;
        }
        if (p.second >= cost && p.first < cost) {
            negatives++;
        }
    }

    ll total = customer;
    if (negatives <= k) {
        total += negatives;
    } else {
        total += k;
    }

    return total;
}


void Vedant() {
    ll n, k;
    cin >> n >> k;
    vll a(n), b(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];

    vector<pair<ll,ll> > temp;
    for (ll i = 0; i < n; i++) temp.pb(mp(a[i], b[i]));

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll mini = a[0], maxi = b[n-1];
    ll ans = 0;

    while (mini <= maxi) {
        ll cost = mini + (maxi - mini) / 2;
        ll customers = solve(cost, temp, k);
        ll profit = cost * customers;

        ans = max(ans, profit);

        ll next_customers = solve(cost + 1, temp, k);
        if ((cost + 1) * next_customers > ans) {
            mini = cost + 1;
        } else {
            maxi = cost - 1;
        }
    }

    cout << ans << endl;
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
