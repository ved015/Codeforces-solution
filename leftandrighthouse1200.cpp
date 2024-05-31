#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool check(int n, int index, int zeroes, int ones) {
    return zeroes >= (index + 1)/ 2 && ones >= (n - index + 1) / 2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<pair<int, pair<int, int> > > m;

        int zeroes = 0, ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zeroes++;
            else ones++;
        }

        m.push_back(make_pair(0, make_pair(0, ones)));

        int tempzeroes = 0, tempones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') tempzeroes++;
            else tempones++;

            m.push_back(make_pair(i + 1, make_pair(tempzeroes, ones - tempones)));
        }

        int mini = INT_MAX;
        int answer = -1;

        for (int i = 0; i < m.size(); i++) {
            if (check(n, m[i].first, m[i].second.first, m[i].second.second)) {
                double ans = 0;
                if(n%2 != 0) ans = n/2 + 0.5;
                else ans = n/2;
                if (abs(ans - m[i].first) < mini) {
                    mini = abs(n / 2 - m[i].first);
                    answer = m[i].first;
                }
            }
        }

        cout << answer << endl;
    }
    return 0;
}
