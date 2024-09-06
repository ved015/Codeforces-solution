#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
#include <queue>
using namespace std;

typedef long long ll;

ll solve(vector<ll>& a, ll k) {
    int n = a.size();
    sort(a.rbegin(), a.rend());
    
    ll score = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            score += a[i];
        } else {
            score -= a[i];
        }
    }

    priority_queue<ll> pq;
    for (int i = 0; i < n - 1; i += 2) {
        pq.push(a[i] - a[i + 1]);
    }

    ll inc = 0;
    while (k > 0 && !pq.empty()) {
        ll val = pq.top();
        pq.pop();
        
        if (val <= k) {
            k -= val;
            inc += val;
        } else {
            inc += k;
            k = 0;
        }
    }
    
    return score - inc;
}

int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << solve(a, k) << "\n";
    }
    
    return 0;
}
