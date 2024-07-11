#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;
            m[a % k]++;
        }
        int ans = 0;

        for (int i = 0; i < k; i++) {
            if (m.find(i) != m.end()) {
                int val = i;
                int rem = (k - val) % k;
                m[val]--;
                if (m[val] == 0) m.erase(val);

                while (m.find(rem) != m.end()) {
                    m[rem]--;
                    if (m[rem] == 0) m.erase(rem);
                    rem = (k - rem) % k;
                }
                ans++;
            }
        }
        for (auto &it : m) {
            ans += it.second;
        }

        cout << ans << endl;
    }
    return 0;
}
