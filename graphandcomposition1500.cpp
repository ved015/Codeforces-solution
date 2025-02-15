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

class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }

}; 

void dfs(int node,vi &vis,vector<vi> &adjls){
    vis[node] = 1;
    for(auto it : adjls[node]){
        if(vis[it] == 0) dfs(it,vis,adjls);
    }
    return;
}

void Vedant(){
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    DisjointSet ds(n);
    vector<pii> adjls;
    for(int i = 0; i < m1; i++){
        int u,v;
        cin >> u >> v;
        adjls.push_back(mp(u,v));
    }

    for(int i = 0; i < m2; i++){
        int u,v;
        cin >> u >> v;
        ds.unionByRank(u,v);
    }

    int remove = 0;
    for(auto &it : adjls){
        if(ds.findUPar(it.first) != ds.findUPar(it.second)){
            remove++;
            it.first = -1;
            it.second = -1;
        }
    }

    vector<vi> final(n + 1);
    for(auto it : adjls){
        if(it.first != -1 && it.second != -1){
            final[it.first].push_back(it.second);
            final[it.second].push_back(it.first); 
        }
    }

    vi vis(n + 1,0);
    int cc1 = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i,vis,final);
            cc1++;
        }
    }
    
    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(ds.findUPar(i));
    }
    int cc2 = s.size();

    cout << remove + cc1 - cc2 << endl;
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