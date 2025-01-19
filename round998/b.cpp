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
        ll n, m;
        cin >> n >> m;

        vector<vector<ll> > a(n, vector<ll>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            sort(a[i].begin(), a[i].end());
        }

        vector<ll> ans;
        bool flag = true;
        ll x = -1;

        vector<pair<ll, ll> > v(n);
        for (int i = 0; i < n; i++) {
            v[i].first = a[i][0];
            v[i].second = i;
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++) {
            if (v[i].first > x) {
                ans.push_back(v[i].second + 1);
                x = v[i].first;
            } else {
                flag = false;
                break;
            }
        }

        if (!flag) {
            cout << -1 << endl;
            return;
        }

        for (int col = 1; col < m; col++) {
            for (int i = 0; i < n; i++) {
                ll cow = ans[i] - 1;
                if (a[cow][col] > x) {
                    x = a[cow][col];
                } else {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }

        if (!flag) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
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