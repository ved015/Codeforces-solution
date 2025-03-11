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

vector<vector<int> > dp;

bool helper(int val,int len){
    if(len == 1) return true;
    
    if(dp[val][len] != -1) return dp[val][len];
    
    bool ans = false;
    // equal to len means k == 1 which is always possible
    for(int i = 2; i <= len; i++){
        if(val%i == 0 && len%i == 0){
            if(helper(val/i,len/i)){
                ans = true;
                break;
            }
        }
    }
    return dp[val][len] = ans;
}

void Vedant(){
    int n,x;
    cin >> n >> x;
    vi a(n);
    for(auto &it : a) cin >> it;

    int sum = 0;
    for(auto it : a) sum += it;

    // if(sum%x != 0){
    //     cout << "NO" << endl;
    //     return;
    // }
    // int val = sum/x;
    // int len = sz(a);
    
    // dp.assign(val + 1, vector<int>(len + 1, -1));
    
    // if(helper(val,len) == true){
    //     cout << "YES" << endl;
    //     return;
    // }
    // cout << "NO" << endl;
    if(sum%n != 0){
        cout << "NO" << endl;
        return;
    }
    if(sum/n == x){
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
