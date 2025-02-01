#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int farthestNode, maxDepth;

void dfs(int node, int par, int depth, vector<vi> &adjls) {
    if (depth > maxDepth) {
        maxDepth = depth;
        farthestNode = node;
    }
    for (auto it : adjls[node]) {
        if (it != par) {
            dfs(it, node, depth + 1, adjls);
        }
    }
}

void findDiameter() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    vector<vi> adjls(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adjls[a].push_back(b);
        adjls[b].push_back(a);
    }

    // Step 1: Find the farthest node from node 1
    maxDepth = -1;
    dfs(1, -1, 0, adjls);
    int firstFarthest = farthestNode;

    // Step 2: Find the farthest node from firstFarthest
    maxDepth = -1;
    dfs(firstFarthest, -1, 0, adjls);
    int diameter = maxDepth;

    cout << diameter << endl;
}

int main() {
    fastio();
    int t = 1;
    while (t--) {
        findDiameter();
    }
    return 0;
}
