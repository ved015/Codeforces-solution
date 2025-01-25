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
// #define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()

void Vedant(){
    ll n, m;
    cin >> n >> m;
    vi a(n);
    vi b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    multiset<ll,greater<ll> > pa, pb;
    for (auto it : a)
    {
        pa.insert(it);
    }
    for (auto it : b)
    {
        pb.insert(it);
    }
    while (true)
    {
        if (pa.empty() && pb.empty())
        {
            cout << "YES" << endl;
            return;
        }
        if (pa.empty() || pb.empty() || sz(pb) > sz(pa))
        {
            cout << "NO" << endl;
            return;
        }
        ll mxb = *pb.begin();
        ll mxa = *pa.begin();
        if (mxa > mxb)
        {
            cout << "NO" << endl;
            return;
        }
        else if (mxa == mxb)
        {
            pa.erase(pa.find(mxa));
            pb.erase(pb.find(mxa));
        }
        else
        {
            ll sb = mxb / 2;
            ll lb = (mxb + 1) / 2;
            pb.insert(sb);
            pb.insert(lb);
            pb.erase(pb.find(mxb));
        }
    }
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