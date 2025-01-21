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

ll max(ll a, ll b, ll c){ return max(a, max(b, c));}
ll min(ll a, ll b, ll c){ return min(a, min(b, c));}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll fact(ll a) { return (a <= 1) ? 1 : a * fact(a - 1); }

vll factors(int n) { vll ans; int l = sqrt(n); for (int i = 1; i <= l; i++) { if (n % i == 0){ if (n/i == i) ans.pb(i); else {ans.pb(i); ans.pb(n/i);}}} return ans;}
string DecimalToBinary(ll num){string str; while(num){if(num & 1) str.pb('1');else str.pb('0');num>>=1;}return str;}
ll BinaryToDecimal(string num){ll ans = 0; ll base = 1; for (int i = sz(num) - 1; i >= 0; i--) {if (num[i] == '1') ans += base; base<<=1;}return ans;}
struct segmenttree
{
    ll n;
    vector<ll> st;

    void init(ll _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    void build(ll node, ll start, ll end, vector<ll> &v)
    {

        ll mid = (start + end) / 2;
        if (start == end)
        {
            st[node] = v[start];
            return;
        }

        build(2 * node + 1, start, mid, v);
        build(2 * node + 2, mid + 1, end, v);

        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void build(vector<ll> &v)
    {
        build(0, 0, n - 1, v);
    }

    ll query(ll start, ll end, ll l, ll r, ll node)
    {

        if (start > r || end < l)
        {
            return 0;
        }


        if (start >= l && end <= r)
        {
            return st[node];
        }

        ll mid = (start + end) / 2;

        ll q1 = query(start, mid, l, r, 2 * node + 1);
        ll q2 = query(mid + 1, end, l, r, 2 * node + 2);

        return q1 + q2;
    }

    ll query(ll l, ll r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(ll start, ll ending, ll node, ll index, ll value)
    {

        if (start == ending)
        {
            st[node] = value;
            return;
        }

        ll mid = (start + ending) / 2;
        if (index <= mid)
        {

            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {

            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];

        return;
    }

    void update(ll x, ll y) // (idx,val)
    {
        update(0, n - 1, 0, x, y);
    }
};

void Vedant(){
   ll n,q;
   cin >> n >> q;
   vll a(n);
   for(int i = 0; i < n; i++) cin >> a[i];

   segmenttree tree;
   tree.init(n);
   tree.build(a);

   for(int i = 0; i < q; i++){
      ll type,a,b;
      cin >> type >> a >> b;
      if(type == 1){
         tree.update(a-1,b);
      }
      else{
         cout << tree.query(a-1,b-1) << endl;
      }
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