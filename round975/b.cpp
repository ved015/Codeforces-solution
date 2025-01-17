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
    ll n,q;
    cin >> n >> q;
    vll a(n),b(q);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < q; i++) cin >> b[i];

    // for each array a segments are (n*n-1)/2
    // so for each poll like 1 2 3 4 5 6 for segments starting with 1
    // 5 will come in two segments 6 in 1 4 in 3 so basically n - i + 1
    // now for segments starting with 2 five will come in 2 it will still come two times
    // so for each idx freq = (n - i + 1)*i + 1
    // 1 3 6 9 11 12
    // means elements >=9 & <= 11 will have freq (n - i + 1)*i + 1
    map<ll,ll> freq;
    for(ll i = 0; i < n; i++){
        if(i < n - 1) freq[(n - i - 1)*(i + 1)] += a[i + 1] - a[i] - 1;
        freq[(n - i)*(i + 1) - 1]++;
    }
    for(auto it : b){
        cout << freq[it] << " ";
    }
    cout << endl;
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