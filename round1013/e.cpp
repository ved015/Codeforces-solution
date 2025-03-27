#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 1;
vector<int> is_prime(MAXN, 1);
vector<int> interesting(MAXN, 0);

void precompute() {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i < MAXN; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    for (int p = 2; p < MAXN; ++p) {
        if (is_prime[p]) {
            for (int g = 1; g * p < MAXN; ++g) {
                int b = g * p;
                interesting[b]++;
            }
        }
    }

    for (int i = 1; i < MAXN; ++i) {
        interesting[i] += interesting[i - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << interesting[n] << endl;
    }

    return 0;
}
