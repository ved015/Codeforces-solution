#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void Vedant() {
    int n, k;
    cin >> n >> k;
    vi a(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> dp(n + 1, 0);


    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (a[j] > i) break;
            if (dp[i - a[j]] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i] == 1) cout << "W";
        else cout << "L";
    }
    cout << endl;
}

int main() {
    fastio();
    int t = 1;
    while (t--) {
        Vedant();
    }
    return 0;
}
