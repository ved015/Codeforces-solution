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

struct SegmentTree {
    ll n;
    vector<ll> st, lazy;

    void init(ll _n) {
        this->n = _n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void propagate(ll node, ll start, ll end) {
        if (lazy[node] != 0) {
            st[node] += lazy[node] * (end - start + 1);

            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    void range_update(ll node, ll start, ll end, ll l, ll r, ll value) {
        propagate(node, start, end);

        if (start > r || end < l) return;

        if (start >= l && end <= r) {
            lazy[node] += value;
            propagate(node, start, end);
            return;
        }

        ll mid = (start + end) / 2;
        range_update(2 * node + 1, start, mid, l, r, value);
        range_update(2 * node + 2, mid + 1, end, l, r, value);

        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    ll point_query(ll node, ll start, ll end, ll index) {
        propagate(node, start, end);

        if (start == end) return st[node];

        ll mid = (start + end) / 2;
        if (index <= mid) {
            return point_query(2 * node + 1, start, mid, index);
        } else {
            return point_query(2 * node + 2, mid + 1, end, index);
        }
    }

    void range_update(ll l, ll r, ll value) {
        range_update(0, 0, n - 1, l, r, value);
    }

    ll point_query(ll index) {
        return point_query(0, 0, n - 1, index);
    }
};

void Vedant() {
    ll n, q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree tree;
    tree.init(n);


    for (int i = 0; i < n; i++) {
        tree.range_update(i, i, a[i]);
    }

    for (int i = 0; i < q; i++) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll a, b, u;
            cin >> a >> b >> u;
            tree.range_update(a - 1, b - 1, u);
        } else if (type == 2) {
            ll k;
            cin >> k;
            cout << tree.point_query(k - 1) << endl;
        }
    }
}

int main() {
    fastio();
    int t = 1;
    while (t--) {
        Vedant();
    }
    return 0;
}
