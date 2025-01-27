#include<bits/stdc++.h>
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
    int x,n;
    cin >> x >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    set<int> s;
    s.insert(0);
    s.insert(x);
    multiset<int> ans;
    // pehle upper boune me 0 and x hai so ans me wo remove kro after adding first
    ans.insert(x - 0);
    for(int i = 0; i < n; i++){
        auto idx1 = s.upper_bound(a[i]);
        // unique hai isliye diff kabhi zero nhi aaayega lower upper dono same result denge
        // 4 6 me 5 beech me so remove 6-4 = 2 add 6-5 and 5-4
        // it will come bewteen two so erase previous distance bw older and add this
        auto idx2 = idx1;
        idx2--;
        // in do index ke beech em aayi so remove 
        int val1 = *idx1;
        int val2 = *idx2;
        ans.erase(ans.find(val1 - val2)); // ek hi iteration remove krni
        ans.insert(val1 - a[i]);
        ans.insert(a[i] - val2);
        s.insert(a[i]);
        cout << *ans.rbegin() << " ";
    }
}


int main(){
    fastio();
    int t = 1;
    while(t--){
       Vedant();
    }
    return 0;
}