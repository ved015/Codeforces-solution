#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> p(n);
        int current = 1;

        for (int i = k - 1; i < n && current <= n; i += k) {
            p[i] = current++;
        }

        for (int i = 0; i < n; i++) {
            if (p[i] == 0) {
                p[i] = current++;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    fastio();
    solve();
    return 0;
}
