#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 200005;

vector<long long> fact(MAXN), invFact(MAXN);



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    precomputeFactorials();
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long sum = 0;
        int med = (k + 1) / 2;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                int l = i;
                int r = n - i - 1;
                long long ways = fac(l, med - 1) * fac(r, k - med) % MOD;
                sum = (sum + ways) % MOD;
            }
        }
        
        cout << sum << endl;
    }
    
    return 0;
}
