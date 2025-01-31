#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    ll x;
    cin >> n >> x;
    
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; // Store original positions
    }
    
    sort(a.begin(), a.end()); // Sort by values
    
    for (int i = 0; i < n; i++) {
        ll target = x - a[i].first;
        int left = i + 1, right = n - 1;
        
        while (left < right) {
            ll sum = a[left].first + a[right].first;
            if (sum == target) {
                cout << a[i].second << " " << a[left].second << " " << a[right].second << "\n";
                return 0;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    cout << "IMPOSSIBLE\n";
    return 0;
}
