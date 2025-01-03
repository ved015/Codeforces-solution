#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    fflush(stdout);
    int ret;
    cin >> ret;
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);


    for (int i = 2; i <= n; i++) {
        a[i - 1] = query(1, i);
    }

    if (a[n - 1] == 0) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }

    string s(n, '0');
    int i = 0;

    while (a[i] == 0) i++;


    for (int j = 0; j < i - a[i]; j++) {
        s[j] = '1';
    }
    for (int j = i; j < n; j++) {
        s[j] = (a[j] > a[j - 1]) ? '1' : '0';
    }

    cout << "! " << s << endl;
    fflush(stdout);
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
