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

int helper(int idx, int i, vi &a) {
    int cnt = 0;
    int n = sz(a);
    for (int j = i + 1; j < n; j++) {
        if (a[idx] > a[j]) cnt++;
    }
    return cnt;
}

void Vedant() {
    int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        int val = 1e9;
        int op1 = 1, op2 = 1;

        for (int l = 0; l < n; ++l) {
            int cg = 0, cl = 0;
            int mini = 0;
            int cur = l;

            for (int r = l; r < n; ++r) {
                int temp;
                if (r == l) {
                    temp = 0;
                } else {
                    if (a[r] > a[l]) {
                        cg++;
                    } else if (a[r] < a[l]) {
                        cl++;
                    }
                    temp = cg - cl;
                }

                if (temp < mini) {
                    mini = temp;
                    cur = r;
                }
            }

            if (mini < val) {
                val = mini;
                op1 = l + 1;
                op2 = cur + 1;
            }
        }

        cout << op1 << " " << op2 << "\n";
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