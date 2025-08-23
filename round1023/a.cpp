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
    int n;
    cin >> n;

    vi a(n);
    for(auto &it : a) cin >> it;

    int o = 0,e = 0;
    set<int> st;
    for(auto &it : a){
        if(it & 1) o++;
        else e++;
        st.insert(it);
    }

    if(sz(st) == 1){
        cout << "NO" << endl;
        return;
    }

    vi ans;
    if(o == 0 || e == 0){
        cout << "YES" << endl;
        int maxi = *max_element(all(a));
        bool flag = false;
        for(auto &it : a){
            if(it == maxi && flag == false){
                ans.push_back(2);
                flag = true;
            }
            else ans.push_back(1);
        }

        for(auto &it : ans) cout << it << " ";
        cout << endl;
        return;
    }

    cout << "YES" << endl;
    for(auto &it : a){
        if(it & 1) ans.push_back(1);
        else ans.push_back(2);
    }

    for(auto &it : ans){
        cout << it << " ";
    }
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