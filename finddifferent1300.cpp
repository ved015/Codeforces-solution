#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        vector<unordered_map<int, int> > freq(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]]++;
            freq[i] = mp;
        }

        int q;
        cin >> q;
        vector<pair<int, int> > queries(q);
        for (int i = 0; i < q; ++i) {
            int a, b;
            cin >> a >> b;
            queries[i] = make_pair(a - 1, b - 1);
        }

        vector<pair<int, int> > ans;
        for (const auto& it : queries) {
            int l = it.first;
            int r = it.second;

            unordered_map<int, int> temp = freq[r];
            if (l - 1 >= 0) {
                for (const auto& pair : freq[l - 1]) {
                    temp[pair.first] -= pair.second;
                    if (temp[pair.first] == 0) {
                        temp.erase(pair.first);
                    }
                }
            }

            if (temp.size() < 2) {
                ans.push_back(make_pair(-1, -1));
            } else {
                auto it = temp.begin();
                int first = it->first;
                ++it;
                int second = it->first;

                int index1 = -1, index2 = -1;
                for (int i = l; i <= r; ++i) {
                    if (nums[i] == first && index1 == -1) {
                        index1 = i + 1;
                    } else if (nums[i] == second && index2 == -1) {
                        index2 = i + 1;
                    }
                    if (index1 != -1 && index2 != -1) break;
                }
                ans.push_back(make_pair(index1, index2));
            }
        }

        for (const auto& it : ans) {
            cout << it.first << " " << it.second << endl;
        }
        cout << endl;
    }
    return 0;
}
