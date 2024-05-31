#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

void players(vector<pair<int, char> > &nums, int n, int m, int x, set<int> &s, int i, map<pair<int, int>, bool> &dp) {
    if (i == m) {
        s.insert(x);
        return;
    }
    if (dp.find(make_pair(i, x)) != dp.end()) {
        return;
    }

    int clocknext = (x + nums[i].first) % n;
    int clockprev = (x + n - nums[i].first) % n;

    clocknext = (clocknext == 0) ? n : clocknext;
    clockprev = (clockprev == 0) ? n : clockprev;

    if (nums[i].second == '?') {
        players(nums, n, m, clocknext, s, i + 1, dp);
        players(nums, n, m, clockprev, s, i + 1, dp);
    } else if (nums[i].second == '0') {
        players(nums, n, m, clocknext, s, i + 1, dp);
    } else {
        players(nums, n, m, clockprev, s, i + 1, dp);
    }

    dp[make_pair(i, x)] = true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        vector<pair<int, char> > nums;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            char b;
            cin >> b;
            nums.push_back(make_pair(a, b));
        }
        set<int> s;
        map<pair<int, int>, bool> dp;  
        players(nums, n, m, x, s, 0, dp);

        cout << s.size() << endl;
        for (auto i : s) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
