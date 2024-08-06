#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, int parent, int iter, int idx, vector<vector<pair<int, int> > > &edges, int &ans) {
    ans = max(ans, iter);
    for(auto [nb, id] : edges[node]) {
        if(nb == parent) continue;
        dfs(nb, node, iter + (id < idx), id, edges, ans);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<pair<int, int> > > edges(n);
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edges[u - 1].push_back(make_pair(v - 1, i));
            edges[v - 1].push_back(make_pair(u - 1, i));
        }

        int ans = 0;
        dfs(0, -1, 1, -1, edges, ans);
        cout << ans << endl;
    }
    return 0;
}
