#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void compute(const string& s, vector<vector<int> >& freq) {
    int n = s.size();
    freq.assign(26, vector<int>(n + 1, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            freq[j][i + 1] = freq[j][i];
        }
        freq[s[i] - 'a'][i + 1]++;
    }
}

int solve(vector<vector<int> >& freqa,vector<vector<int> >& freqb, int left, int right) {
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        int a = freqa[i][right] - freqa[i][left - 1];
        int b = freqb[i][right] - freqb[i][left - 1];
        ans += abs(a - b);
    }
    return ans / 2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        vector<vector<int> > freqa, freqb;
        compute(a, freqa);
        compute(b, freqb);

        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << solve(freqa, freqb, l, r) << endl;
        }
    }
    return 0;
}
