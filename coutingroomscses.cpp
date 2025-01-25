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

void dfs(int r,int c,vector<vi> &vis,vector<vi> &adjls){

    int n = sz(adjls);
    int m = sz(adjls[0]);

    vis[r][c] = true;
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,-1,1};

    for(int i = 0; i < 4; i++){
        int nrow = r + dr[i];
        int ncol = c + dc[i];

        if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && adjls[nrow][ncol] == 1){
            dfs(nrow,ncol,vis,adjls);
        }
    }

    return;
}

void Vedant(){
    int n,m;
    cin >> n >> m;
    vector<vi> adjls(n,vi(m,-1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch;
            cin >> ch;
            if(ch == '#') adjls[i][j] = 0;
            else adjls[i][j] = 1;
        }
    }

    vector<vi> vis(n,vi(m,false));
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && adjls[i][j] == 1){
                ans++;
                dfs(i,j,vis,adjls);
            }
        }
    }
    cout << ans;
}


int main(){
    fastio();
    int t = 1;
    while(t--){
       Vedant();
    }
    return 0;
}