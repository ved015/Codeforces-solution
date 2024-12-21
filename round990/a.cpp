#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef vector<int> vi;
typedef long long ll;


set<ll> generateOddSquares() {
    set<ll> oddSquares;
    ll k = 1;
    while (k <= 99) {
        oddSquares.insert(k * k);
        k += 2;
    }
    return oddSquares;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    static set<ll> sqs = generateOddSquares();

    ll answer = 0;
    ll cursum = 0;
    for (int i = 0; i < n; i++) {
        cursum += a[i];
        if (sqs.find(cursum) != sqs.end()) {
            answer++;
        }
    }
    cout << answer << endl;
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
