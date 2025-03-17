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
    ll n,k;
    cin >> n >> k;
    vll a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // vector<pair<ll,int> > temp(n);
    // for(int i = 0; i < n; i++){
    //     temp[i] = mp(a[i],i);
    // }
    // sort(all(temp));
    // vi idx;
    // for(int i = n - 1; i >= n - k; i--){
    //     idx.pb(temp[i].second);
    // }
    // bool flag = true;
    // for(int i = 0; i < sz(idx) - 1; i++){
    //     if(idx[i] + 1 != idx[i+1]) flag = false;
    // }
    // if(flag){

    // }
    vll temp = a;
    sort(all(temp));
    if(k == 1){
        if(a[0] == temp[n-1] || a[n-1] == temp[n-1]){
            cout << temp[n-1] + temp[n-2] << endl;
            return;
        }
        else{
            cout << temp[n-1] + max(a[0],a[n-1]) << endl;
            return;
        }
    }
    ll sum = 0;
    for(int i = n - 1; i >= n - k - 1; i--){
        sum += temp[i];
    }
    cout << sum << endl;
    return;
    // pos of k maximum elements
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