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
    ll n,x;
    cin >> n >> x;
    string temp = DecimalToBinary(x);
    // the bit which is 1 in all will be one in all
    // reverse(all(temp));
    vector<int> cnt(32);
    for(int i = 0; i < sz(temp); i++){
        if(temp[i] == '1') cnt[i] = n;
        else cnt[i] = 0;
    }
    int ans = 0;
    bool flag = true;
    for(int j = 0; j <= x && j < n; j++){
        string a = DecimalToBinary(j);
        if(j == 0) a = "0";
        // reverse(all(a));
        for(int i = 0; i < sz(a); i++){
            if(a[i] == '1' && temp[i] == '0') flag = false;
            if(a[i] == '0' && temp[i] == '1'){
                if(cnt[i] <= 1) flag = false;
                else cnt[i]--;
            }
        }
        if(flag == false){
            // cout << a << endl;
            ans = j - 1;
            break;
        }
    }
    if(flag){
        if(x >= n){
            ans = n - 1;
            int val = 0;
            for(int i = 0; i <= ans; i++) val = val | i;
            if(val != x) ans--; 
        }
        else ans = x;

    }
    // cout << temp << endl;
    // cout << ans << endl;
    for(int i = 0; i <= ans; i++) cout << i << " ";
    for(int i = ans + 1; i < n; i++) cout << x << " ";
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