#include <bits/stdc++.h>
#include<iostream>
#include<set>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(x) x.begin(), x.end()

void Vedant() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    multiset<int> ms;
    for (auto it : a) ms.insert(it);

    for (auto it : b) {
        auto lb = ms.lower_bound(it);
        int ans = -1;

        if (lb != ms.end() && *lb == it) {
            ans = *lb;
        } 
        if (lb != ms.begin()) {
            auto prev_it = prev(lb);
            if (ans == -1) {
                ans = *prev_it;
            }
        }
        if (lb == ms.end() && !ms.empty()) {
            int val = *prev(ms.end());
            if (val <= it) ans = val;
        }

        if (ans != -1) {
            cout << ans << endl;
            ms.erase(ms.find(ans));
        } else {
            cout << -1 << endl;
        }
    }
    return;
}

int main() {
    fastio();
    int t = 1;
    while (t--) {
        Vedant();
    }
    return 0;
}
