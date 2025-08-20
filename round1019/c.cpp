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

int helper1(vll a,int k){
    int cnt = 0,idx = -1;
    for(int i = 0; i < sz(a) - 2; i++){
        if(a[i] <= k) cnt++;
        if(cnt >= ceil((i + 1)/2.0)){
            idx = i;
            break;
        }
    }
    if(idx == -1) return false;
    int len = (idx + 1);

    if(len & 1 && idx < sz(a) - 3){
        if(a[idx + 1] > k) idx++;
    }

    cnt = 0;
    for(int i = idx + 1; i < sz(a) - 1; i++){
        if(a[i] <= k) cnt++;
        if(cnt >= ceil((i - idx)/2.0)) return true;
    }
    return false;
}

int helper2(vll a,int k){
    int cnt = 0,idx = -1;
    for(int i = 0; i < sz(a) - 2; i++){
        if(a[i] <= k) cnt++;
        if(cnt >= ceil((i + 1)/2.0)){
            idx = i;
            break;
        }
    }
    if(idx == -1) return false;
    cnt = 0;
    for(int i = sz(a) - 1; i > idx + 1; i--){
        if(a[i] <= k) cnt++;
        if(cnt >= ceil((sz(a) - i)/2.0)) return true;
    }
    return false;
}

int helper3(vll a,int k){
    int cnt = 0,idx = -1;
    for(int i = sz(a) - 1; i >= 2; i--){
        if(a[i] <= k) cnt++;
        if(cnt >= ceil((sz(a) - i)/2.0)){
            idx = i;
            break;
        }
    }
    if(idx == -1) return false;
    int len = sz(a) - idx;
    if(len & 1 && idx > 3){
        if(a[idx - 1] > k) idx--;
    }
    cnt = 0;
    for(int i = idx - 1; i >= 1; i--){
        if(a[i] <= k) cnt++;
        if(cnt >= ceil((idx - i)/2.0)) return true;
    }
    return false;
}

void Vedant(){
    ll n,k;
    cin >> n >> k;

    vll a(n);
    for(auto &it : a) cin >> it;

    if(helper1(a,k) || helper2(a,k) || helper3(a,k)){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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