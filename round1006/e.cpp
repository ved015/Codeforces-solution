#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<climits>
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

int helper(int pos, int op, int prev, const string& s, const vector<int>& a, 
           vector<vector<vector<int>>>& memo) {
    int n = s.length();
    
    if (pos == n) {
        return 0;
    }
    
    if (memo[pos][op][prev+1] != -1) {
        return memo[pos][op][prev+1];
    }
    
    int result = INT_MAX;
    
    char curr = 'R';
    if (prev != -1 && prev >= pos) {
        curr = 'B';
    }
    
    int penalty = (curr != s[pos]) ? a[pos] : 0;
    int newpenalty = helper(pos + 1, op, prev, s, a, memo);
    if (newpenalty != INT_MAX) {
        result = min(result, max(penalty, newpenalty));
    }
    
    if (op > 0) {
        for (int length = 1; pos + length - 1 < n; length++) {
            int e = pos + length - 1;
            int segpenalty = 0;
            
            for (int i = pos; i <= e; i++) {
                if ('B' != s[i]) {
                    segpenalty = max(segpenalty, a[i]);
                }
            }
            
            int newpenalty = helper(e + 1, op - 1, e, s, a, memo);
            if (newpenalty != INT_MAX) {
                result = min(result, max(segpenalty, newpenalty));
            }
        }
    }
    
    memo[pos][op][prev+1] = result;
    return result;
}

int solve(int n, int k, const string& s, const vector<int>& a) {
    if (k >= n) {
        return 0;
    }
    
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(k+1, vector<int>(n+1, -1)));
    
    return helper(0, k, -1, s, a, memo);
}

void Vedant(){
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << solve(n, k, s, a) << "\n";
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
