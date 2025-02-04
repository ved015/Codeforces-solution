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
    ll n;
    cin >> n;
    vector<vll> adj(n + 1);
    vll dist(n + 1, 0), subtree_size(n + 1, 1);

    for(ll i = 1; i < n; i++){
        ll a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    function<void(ll, ll)> dfs1 = [&](ll node, ll parent) {
        for (ll neighbor : adj[node]) {
            if (neighbor == parent) continue;
            dfs1(neighbor, node);
            subtree_size[node] += subtree_size[neighbor];
            dist[node] += dist[neighbor] + subtree_size[neighbor];
        }
    };


    function<void(ll, ll)> dfs2 = [&](ll node, ll parent) {
        for (ll neighbor : adj[node]) {
            if (neighbor == parent) continue;
            dist[neighbor] = dist[node] + (n - 2 * subtree_size[neighbor]);
            dfs2(neighbor, node);
        }
    };

    dfs1(1, -1);
    dfs2(1, -1);

    for(ll i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    return;
}


int main(){
    fastio();
    int t = 1;
    while(t--){
       Vedant();
    }
    return 0;
}