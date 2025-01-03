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

class PrimeChecker {
private:
    vector<bool> is_prime;
    int max_limit;
    void generateSieve(int limit) {
        is_prime.assign(limit + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= limit; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
public:
    PrimeChecker(int limit) : max_limit(limit) {
        generateSieve(limit);
    }
    bool isPrime(int n) {
        return is_prime[n];
    }
};
PrimeChecker checker(3*(2e5));

void Vedant(){
    int n;
    cin >> n;
    // 1 3 5 2 4
    // n + n - 1 -> odd
    // 1 3 2
    vi ans(n);
    int j = 0;
    for(int i = 1; i <= n; i += 2){
        ans[j] = i;
        j++;
    }
    int idx = j;
    for(int i = 2; i <= n; i += 2){
        ans[j] = i;
        j++;
    }
    bool flag = false;
    for(int i = idx; i < n; i++){
        if(checker.isPrime(ans[idx - 1] + ans[i]) == false){
            swap(ans[idx],ans[i]);
            flag = true;
            break;
        }
    }
    if(flag){
        for(auto it : ans) cout << it << " ";
        cout << endl;
    }
    else cout << -1 << endl;
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