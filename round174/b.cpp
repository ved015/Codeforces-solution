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

bool check(int idx,vi &group,vector<pii> &temp){
    int r = temp[idx].first;
    int c = temp[idx].second;

    bool flag = true;
    for(auto &it : group){
        int pr = temp[it].first;
        int pc = temp[it].second;
        if((r == pr && (pc == c + 1 || pc == c - 1)) || (c == pc && (r == pr + 1 || r == pr - 1))) return false;
    }
    group.pb(idx);
    return true;
}

void Vedant(){
    int n,m;
    cin >> n >> m;

    map<int,vector<pii> > pos;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            pos[val].push_back(mp(i,j));
        }
    }

    map<int,int> final;
    for(auto it : pos){
        vector<pii> temp = it.second;
        int cnt = 0;
        vi vis(sz(temp),0);
        
        for(int i = 0; i < sz(temp); i++){
            if(vis[i] == 1) continue;
            vi group;
            group.pb(i);
            vis[i] = 1;
            for(int j = 0; j < sz(temp); j++){
                if(vis[j] == 0){
                    if(check(j,group,temp)) vis[j] = 1;
                }
            }
            cnt++;
            bool flag = true;
            for(auto &it : vis) if(it == 0) flag = false;
            if(flag) break;
        }
        final[it.first] = cnt;
    }

    int maxi = -1;
    int clr = -1;
    int ans = 0;
    for(auto it : final){
        if(it.second > maxi){
            maxi = it.second;
            clr = it.first;
        }
    }

    for(auto it : final){
        if(it.first == clr) continue;
        else ans += it.second;
    }
    cout << ans << endl;
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