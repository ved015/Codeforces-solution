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

// void dfs(int node, vector<vi> &adjls, vector<bool> &visited) {
//     visited[node] = true;
//     for (int neighbor : adjls[node]) {
//         if (!visited[neighbor]) {
//             dfs(neighbor, adjls, visited);
//         }
//     }
// }

// int connectedcomp(vector<vi> &adjls) {
//     int n = adjls.size();
//     vector<bool> visited(n, false);
//     int count = 0;

//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) {
//             count++;
//             dfs(i, adjls, visited);
//         }
//     }

//     return count;
// }

int check(int node, vi &indegree, vector<vi> &adjls, set<pii> &s) {

    s.erase(mp(indegree[node],node));

    for (auto &it : adjls[node]) {
        s.erase(mp(indegree[it],it));
        indegree[it]--;
        s.insert(mp(indegree[it],it));
    }

    int maxi =  s.rbegin()->first;

    // make set back to original better than copy
    s.insert(mp(indegree[node],node));
    for (int it : adjls[node]) {
        s.erase(mp(indegree[it],it));
        indegree[it]++;
        s.insert(mp(indegree[it],it));
    }

    return maxi;
}

void Vedant(){
    int n;
    cin >> n;
    vi indegree(n);
    vector<vi> adjls(n);
    int maxdegree = -1;
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        indegree[u]++;
        indegree[v]++;
        maxdegree = max(maxdegree,max(indegree[u],indegree[v]));
        adjls[u].pb(v);
        adjls[v].pb(u);
    }

    set<pii> degree;
    for (int i = 0; i < n; i++) {
        degree.insert(mp(indegree[i],i));
    }
    int val = degree.rbegin()->first;
    // for(auto it : temp) cout << it << " ";
    // cout << endl;
    // cout << secondmax << endl;

    // int ans = connectedcomp(adjls); 
    int ans = 1;
    // cout << ans << endl;

    int maxi = INT_MIN,node = -1;
    // maxi + secondmaxi must me maximised
    for(int i = 0; i < n; i++){
        int val = check(i,indegree,adjls,degree);
            // cout << i + 1 << " " << indegree[i] << " " << val << endl;
            // for(auto it : adjls[i]) cout << it + 1 << " ";
            // cout << endl;
        if(val + indegree[i] > maxi){
            maxi = val + indegree[i]; 
            node = i;
        }
    }

    // node removed so components created is indegree[i] - 1
    // node removed so change indegree of nodes connected to it and make its indegree -1

    // cout << node << endl;    

    ans += indegree[node] - 1;
    for(auto &it : adjls[node]){
        indegree[it]--;
    }
    indegree[node] = -1;

    // for this just take max no need to handle rest cases
    maxi = INT_MIN,node = -1;
    for(int i = 0; i < n; i++){
        if(indegree[i] > maxi){
            maxi = indegree[i]; 
            node = i;
        }
    }

    // cout << node << endl; 
    ans += maxi - 1;

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