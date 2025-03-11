// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include <sstream>
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
    int n;
    cin >> n;
    cin.ignore();
    int extra = 0,prev = 0;
    int l = 1,r = 1;
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        // cout << s << endl;
        stringstream ss(s);
        char op1, op2;
        int d1, d2;
        ss >> op1 >> d1 >> op2 >> d2;

        // cout << op1 << op2 << d1 << d2 << endl;
        if(op1 == '+' && op2 == '+'){
            extra += (d1 + d2);
            prev += d1 + d2;
        }
        else if(op1 == 'x' && op2 == '+'){
            // op1 is multiply so l me saare daal do ek ko chodke and r me 1 rakho taaki add bhi ho jaaye
            // isse no of new customers maximise ho jayenge
            // prev = extra;
            l = l + prev;
            r = 1;
            extra += (l)*(d1 - 1) + d2;
            prev = (l)*(d1 - 1) + d2;
        }
        else if(op1 == '+' && op2 == 'x'){
            // same as above bas ab r me prioritise karenge
            // prev = extra
            l = 1;
            r = r + prev;
            extra += d1 + (r)*(d2 - 1);
            prev = d1 + (r)*(d2 - 1);
        }
        else{
            //isme to for loop lagake max increment ka dekho
            int ans = INT_MIN;
            int val = -1;
            // prev = extra;
            for(int i = 0; i <= prev; i++){
                int gain = (l + i)*(d1 - 1) + (r + (prev - i))*(d2 - 1);
                if(gain > ans){
                    ans = gain;
                    val = i;
                }
            }
            l = l + val;
            r = r + (prev - val);
            extra += ans;
            prev = ans;
        }
    }
    cout << 2 + extra << endl;
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