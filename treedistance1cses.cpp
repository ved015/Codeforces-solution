#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef long long ll;

int n;
vector<vi> adj;
vi distA, distB;  // Stores distances from two farthest nodes A and B

void dfs(int node, int parent, vi &dist) {
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dist[neighbor] = dist[node] + 1;
            dfs(neighbor, node, dist);
        }
    }
}

int find_farthest(int start, vi &dist) {
    fill(dist.begin(), dist.end(), 0);
    dfs(start, -1, dist);
    return max_element(dist.begin(), dist.end()) - dist.begin();
}

void solve() {
    cin >> n;
    adj.assign(n + 1, vi());
    distA.assign(n + 1, 0);
    distB.assign(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Step 1: Find the farthest node from an arbitrary node (1)
    int A = find_farthest(1, distA);

    // Step 2: Find the farthest node from A (this gives diameter endpoint B)
    int B = find_farthest(A, distA);

    // Step 3: Compute distances from B
    int temp = find_farthest(B, distB);

    // Compute final max distance for each node
    for (int i = 1; i <= n; i++) {
        cout << max(distA[i], distB[i]) << " ";
    }
    cout << "\n";
}

int main() {
    fastio();
    solve();
    return 0;
}
