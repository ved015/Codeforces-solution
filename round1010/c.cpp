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

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll fact(ll a) { return (a <= 1) ? 1 : a * fact(a - 1); }

vll factors(int n) { vll ans; int l = sqrt(n); for (int i = 1; i <= l; i++) { if (n % i == 0){ if (n/i == i) ans.pb(i); else {ans.pb(i); ans.pb(n/i);}}} return ans;}
string DecimalToBinary(ll num){string str; while(num){if(num & 1) str.pb('1');else str.pb('0');num>>=1;}return str;}
ll BinaryToDecimal(string num){ll ans = 0; ll base = 1; for (int i = sz(num) - 1; i >= 0; i--) {if (num[i] == '1') ans += base; base<<=1;}return ans;}

void Vedant(){
    ll n, m;
    cin >> n >> m;
    vll a(m);
    for (int i = 0; i < m; i++){
        cin >> a[i];
    }
    
    // for each color if we paint x then n-x should be done with remaining color
    vll temp1(m), temp2(m);
    for (int i = 0; i < m; i++){
        temp1[i] = min(n - 1, a[i]); // minimum one plank of one color remaining from other
        temp2[i] = max(1LL, n - a[i]);
    }
    
    vll plank = temp2;
    sort(all(plank));
    

    vll ps(m + 1, 0);
    for (int i = 0; i < m; i++){
        ps[i + 1] = ps[i] + plank[i];
    }
    
    ll ans = 0;
    for (int i = 0; i < m; i++){
        ll x = temp1[i];
        ll k = upper_bound(plank.begin(), plank.end(), x) - plank.begin(); // elements smaller than that
        if(k <= 0) continue;
        ll tot = (ll)k * (x + 1LL) - ps[k];
        if(temp2[i] <= x){
            tot -= (x - temp2[i] + 1LL);
        }
        
        ans += tot;
    }
    
    cout << ans << "\n";
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