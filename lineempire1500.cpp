#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
typedef long long ll;
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        ll ans = 0;
        int p = 0;
        int conquered = 0, pc = 0;
        for (int i = 0; i < n; ++i) {
            ll c1 = 1LL * b * (n - pc - 1) * (conquered - p);
            ll c2 = 1LL * a * (conquered - p);
            if (c1 < c2) {
                ans += 1LL * b * (v[i] - p);
            } else {
                ans += c2 + 1LL * b * (v[i] - conquered);
                p = conquered;
            }
            pc = i;
            conquered = v[i];
        }
        cout << ans << '\n';
    }

    return 0;
}