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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }
 
    set<int> pos1;
    for (int i = 1; i < n + 1; i++) {
        if (a[i] == 1)
            pos1.insert(i); // logn
    } // nlogn
 
    int l = 1, r = n;
    vector<pair<int, int>> ans;
    while (l < r) {
        if (a[l] == 0) {
            l++;
            continue;
        }
        while (r > l && a[r] != 0)
            r--;
        if (r <= l)
            break;
 
        if (a[l] == 1) {
            swap(a[l], a[r]);
            ans.push_back({l, r});
            pos1.erase(l);  // logn
            pos1.insert(r); // logn
        } else {
            int j = *pos1.rbegin();
            swap(a[l], a[j]);
            swap(a[l], a[r]);
            ans.push_back({l, j});
            ans.push_back({l, r});
            pos1.erase(j);  // logn
            pos1.insert(r); // logn
        }
        l++;
    } // nlogn
    
    r = n;
    while (l < r) {
        if (a[l] == 1) {
            l++;
            continue;
        }
        while (r > l && a[r] == 2) {
            r--;
        }
        if (r <= l)
            break;
        swap(a[l], a[r]);
        ans.push_back({l, r});
        l++;
    } // n
 
    cout << ans.size() << '\n';
    for (auto [i, j] : ans)
        cout << i << ' ' << j << '\n';
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