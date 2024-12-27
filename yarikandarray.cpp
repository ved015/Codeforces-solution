#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = a[0];
    int mn = min(0, a[0]), sum = a[0];
    for (int i = 1; i < n; ++i) {
        if (abs(a[i] % 2) == abs(a[i - 1] % 2)) {
            mn = 0;
            sum = 0;
        }
        sum += a[i];
        ans = max(ans, sum - mn);
        mn = min(mn, sum);
    }
    cout << ans << endl;
}
 
int main() {
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}