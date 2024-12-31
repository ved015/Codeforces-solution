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

bool dfs(char dir,char prevdir,int r,int c,vector<vector<char> > &mat,vector<vector<bool> > &visited){
    int n = sz(mat);
    int m = sz(mat[0]);

    if(r >= n || r < 0 || c < 0 || c >= m) return false;
    if(visited[r][c]) return true;

    visited[r][c] = true;

    if(dir == '?'){
        char newdir;
        if(prevdir == 'U') newdir = 'D';
        else if(prevdir == 'L') newdir = 'R';
        else if(prevdir == 'R') newdir = 'L';
        else newdir = 'U';

        mat[r][c] = newdir;
        return true;
    }

    if(dir == 'U' && r > 0) return dfs(mat[r - 1][c],dir,r - 1,c,mat,visited);
    if(dir == 'D' && r < n - 1) return dfs(mat[r + 1][c],dir,r + 1,c,mat,visited);
    if(dir == 'L' && c > 0) return dfs(mat[r][c - 1],dir,r,c - 1,mat,visited);
    if(dir == 'R' && c < m - 1) return dfs(mat[r][c + 1],dir,r,c + 1,mat,visited);
    
    return false;

}

bool cycle(int r,int c,vector<vector<char> > &mat,vector<vector<bool> > &visited){
    int n = sz(mat);
    int m = sz(mat[0]);

    if(r >= n || r < 0 || c < 0 || c >= m) return false;
    if(visited[r][c]) return true;

    visited[r][c] = true;

    if(mat[r][c] == 'U') return cycle(r - 1,c,mat,visited);
    if(mat[r][c] == 'D') return cycle(r + 1,c,mat,visited);
    if(mat[r][c] == 'L') return cycle(r,c - 1,mat,visited);
    if(mat[r][c] == 'R') return cycle(r,c + 1,mat,visited);
    
    return false;

}
void Vedant(){
    int n,m;
    cin >> n >> m;
    vector<vector<char> > mat(n,vector<char>(m,0));
    vector<pii> pos;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch;
            cin >> ch;
            mat[i][j] = ch;
            if(ch == '?') pos.pb(mp(i,j));
        }
    }
    // if(sz(pos) == n*m){
    //     cout << n*m << endl;
    //     return;
    // }

    string dir = "UDLR";
    while(true){
        vector<vector<char> > temp = mat;
        for(auto it : pos){
            int r = it.first;
            int c = it.second;
            if(mat[r][c] == '?'){
                bool flag = false;
                char ch;
                for(auto num : dir){
                    char prev = '#';
                    vector<vector<bool> > visited(n,vector<bool>(m,false));
                    if(dfs(num,prev,r,c,mat,visited)){
                        flag = true;
                        ch = num;
                        break;
                    }
                }
                if(flag) mat[r][c] = ch;
            }
        }
        if(temp == mat) break;
    }

    for(auto &it : mat){
        for(auto &num : it){
            if(num == '?') num = 'U';
        }
    }

    // // no of cyles using dfs
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vector<vector<bool> > visited(n,vector<bool>(m,false));
            if(cycle(i,j,mat,visited)) ans++;
        }
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