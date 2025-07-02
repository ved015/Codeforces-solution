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

int findGreaterAfterIndex(int start,int end,int val,vi &a){
    int result = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(a[mid] >= val){
            result = mid;
            end = mid - 1;
        }
        else start = mid + 1;
    }
    return result;
}
int findSmallerAfterIndex(int start,int end,int val,vi &a){
    int result = -1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(a[mid] <= val){
            result = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    return result;
}
void Vedant(){
    int n;
    cin >> n;
    vi a(n);
    for(auto &it : a) cin >> it;
    sort(all(a));

    int maxi = *max_element(all(a));

    // brute force is n^3 iterate through triplets and find such that 
    // it satisfies both condition a1 + a2 + a3 > maxi && a1 + a2 > a3
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int val1 = a[i],val2 = a[j];
            int idx1 = findGreaterAfterIndex(j + 1,n - 1,maxi + 1 - val1 - val2,a); // bob selects maxi and a choose from rest
            int idx2 = findSmallerAfterIndex(j + 1,n - 1,val1 + val2 - 1,a); // bob discolour one of a
            // cout << idx1 << " " << idx2 << endl;
            if(idx2 >= idx1 && idx1 != -1 && idx2 != -1) ans += (idx2 - idx1 + 1);
        }
    }
    cout << ans << endl;
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