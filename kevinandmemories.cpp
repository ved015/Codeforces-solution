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

ll positionfromlast(ll x, const vll &temp) {
    auto it = lower_bound(temp.begin(), temp.end(), x);
    return distance(it, temp.end());
}

void Vedant(){
    int n,m;
    cin >> n >> m;
    vll a(n),b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    vll temp = a;
    sort(temp.begin(),temp.end());

    vll basic(m);
    for(int  i = 0; i < m; i++){
        if(b[i] <= a[0]) basic[i] = 1;
        else basic[i] = positionfromlast(b[i],temp) + 1;
    }

    sort(basic.begin(),basic.end());
    ll sum = 0;
    for(auto it : basic) sum += it;

    vll ans(m);
    ans[0] = sum;
    for(int k = 2; k <= m; k++){
        sum = 0;
        for(int i = k - 1; i < m; i += k) sum += basic[i];
        ans[k - 1] = sum;
    }

    for(auto it : ans) cout << it << " ";
    cout << endl;
    return;
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