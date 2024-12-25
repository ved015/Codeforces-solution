// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<long long> vll;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

void Vedant() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, pair<int, int> > m; // {number,{index,diff}}
    for (int i = 0; i < n; i++) {
        if (m.find(a[i]) == m.end()) {
            m[a[i]] = mp(i, i + 1); // basically first index will tell that for 
            //this number to be amazing minimum length is  i + 1   
        } else {
            int idx = m[a[i]].first;
            int diff = m[a[i]].second;
            diff = max(diff,i - idx);
            m[a[i]] = mp(i, diff);
        }
    }

    for(auto &it : m){
        int idx = it.second.first;
        int diff = it.second.second;
        if(n - idx > diff) it.second.second = n - idx;
    }
    vector<pii> possibleLengths; // number and mindiff required
    for (auto it : m) {
        possibleLengths.pb(mp(it.second.second, it.first));
    }

    sort(possibleLengths.begin(), possibleLengths.end());

    // for (auto it : possibleLengths) cout << it.first << " " << it.second << endl;
    for (int i = 1; i < sz(possibleLengths); i++) {
        if (possibleLengths[i].first >= possibleLengths[i - 1].first) {
            possibleLengths[i].second = min(possibleLengths[i - 1].second, possibleLengths[i].second);
        }
    }
    // for (auto it : possibleLengths) cout << it.first << " " << it.second << endl;

    for (int k = 1; k <= n; k++) {
        int l = 0, r = sz(possibleLengths) - 1;
        int result = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (possibleLengths[mid].first <= k) {
                result = possibleLengths[mid].second;
                l = mid + 1;
            }
            else if(possibleLengths[mid].first > k) r = mid - 1;
            else l = mid + 1;
        }
        cout << result << " ";
    }
    cout << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        Vedant();
    }
    return 0;
}
