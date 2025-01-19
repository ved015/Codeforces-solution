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

void Vedant(){
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    vi indegree1(n,0),indegree2(n,0);
    map<int,vi> edges;
    for(int i = 0; i < m1; i++){
        int a,b;
        cin >> a >> b;
        indegree1[a-1]++;
        indegree1[b-1]++;
        edges[a - 1].pb(b - 1);
        edges[b - 1].pb(a - 1);
    }
    for(int i = 0; i < m2; i++){
        int a,b;
        cin >> a >> b;
        indegree2[a-1]++;
        indegree2[b-1]++;
    }

    // for(auto it : edges){
    //     cout << it.first << endl;
    //     for(auto num : edges[it.first]){
    //         cout << num << " ";
    //     }
    //     cout << endl;
    //     cout << endl;
    // }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(indegree1[i] <= indegree2[i]){
            int diff = indegree2[i] - indegree1[i];
            ans += diff;
            indegree1[i] += diff;
        }
        else{
            ans += indegree1[i] - indegree2[i];
            indegree1[i] = indegree2[i];
            for(auto &it : edges[i]){
                indegree1[it]--;
            }
        }
    }
    int extrasum = 0;
    for(int i = 0; i < n; i++){
        if(indegree1[i] <= indegree2[i]){
            extrasum += indegree2[i] - indegree1[i];
        }
    }

    cout << ans + (extrasum/2) << endl;
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