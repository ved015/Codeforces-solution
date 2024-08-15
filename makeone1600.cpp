#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;
const int maxi = 200000;

int main() {
    vector<vector<long long> > precompute(maxi + 1, vector<long long>(10));
    
    for (int d = 0; d <= 9; ++d) {
        precompute[0][d] = 1;
    }
    
    for (int i = 1; i <= maxi; ++i) {
        precompute[i][0] = (precompute[i-1][1])%mod;
        precompute[i][1] = (precompute[i-1][2])%mod;
        precompute[i][2] = (precompute[i-1][3])%mod; 
        precompute[i][3] = (precompute[i-1][4])%mod;
        precompute[i][4] = (precompute[i-1][5])%mod;
        precompute[i][5] = (precompute[i-1][6])%mod;
        precompute[i][6] = (precompute[i-1][7])%mod;
        precompute[i][7] = (precompute[i-1][8])%mod;
        precompute[i][8] = (precompute[i-1][9])%mod;
        precompute[i][9] = (precompute[i-1][1] + precompute[i-1][0]) % mod;
    }
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        int m;
        cin >> n >> m;
        
        long long ans = 0;
        while (n > 0) {
            int digit = n % 10;
            ans = (ans + precompute[m][digit]) % mod;
            n /= 10;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
