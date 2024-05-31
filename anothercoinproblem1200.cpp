#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long int

using namespace std;

int main() {
    vector<ll> coins;
    coins.push_back(1);
    coins.push_back(3);
    coins.push_back(6);
    coins.push_back(10);
    coins.push_back(15);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (ll i = 1; i <= n; i++) {
            for (auto coin : coins) {
                if (i >= coin && dp[i - coin] != LLONG_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        cout << (dp[n] == LLONG_MAX ? -1 : dp[n]) << endl;
    }

    return 0;
}
