#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;
class DisjointSet {
public:
 
	vector<ll> rank, parent, size;
 
	DisjointSet(ll n) {
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for(ll i = 1; i <= n; i++) parent[i] = i;
	}
 
	void unionByRank(ll x, ll y) {
 
		ll par_x = findPar(x);
		ll par_y = findPar(y);
 
		if(par_x == par_y) return;
 
		if(rank[par_x] < rank[par_y]) {
			parent[par_x] = par_y;
		} else if(rank[par_y] < rank[par_x]) {
			parent[par_y] = par_x;
		} else {
			parent[par_x] = par_y;
			rank[par_y]++;
		}
	}
 
	void unionBySize(ll x, ll y) {
 
		ll par_x = findPar(x);
		ll par_y = findPar(y);
 
		if(par_x == par_y) return;
 
		if(size[par_x] < size[par_y]) {
			parent[par_x] = par_y;
			size[par_y] += size[par_x];
		} else {
			parent[par_y] = par_x;
			size[par_x] += size[par_y];
		}
	}
 
	ll findPar(ll x) {
 
		if(parent[x] == x) return x;
 
		return parent[x] = findPar(parent[x]);
 
	}
 
};
int main(){
    ll n, m;
    cin >> n >> m;
    
    DisjointSet ds(n);
    for(ll i = 0; i < m; i++) {
        ll x;
        cin >> x;
    
        if(x == 0) continue;
    
        ll u;
        cin >> u;
    
        for(ll j = 0; j < x - 1; j++) {
            ll v;
            cin >> v;
            ds.unionBySize(u, v);
        }
    }
    
    for(ll i = 1; i <= n; i++) {
        cout << ds.size[ds.findPar(i)] << " ";
    }
    cout << endl;
    return 0;
}