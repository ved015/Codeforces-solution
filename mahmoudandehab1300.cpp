#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(const vector<vector<int> >& adjls, vector<int>& left, vector<int>& right) {
    queue<pair<int, int> > q;
    vector<bool> visited(adjls.size(), false);

    q.push(make_pair(0, 0));
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int count = q.front().second;
        q.pop();

        if (count % 2 == 0)
            left.push_back(node);
        else
            right.push_back(node);

        for (int i = 0; i < adjls[node].size(); ++i) {
            int neighbor = adjls[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(make_pair(neighbor, count + 1));
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > adjls(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adjls[a - 1].push_back(b - 1);
        adjls[b-1].push_back(a-1);
    }

    vector<int> left, right;
    bfs(adjls, left, right);

    long long val = left.size()*right.size();
    cout << val - (n-1) << endl;

    return 0;
}
