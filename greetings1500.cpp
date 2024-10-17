#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> nums(n);
        
        for (int i = 0; i < n; i++) {
            int start, end;
            cin >> start >> end;
            nums[i] = make_pair(start, end);
        }
        
        sort(nums.begin(), nums.end());
        
        ordered_set st;
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans += st.size() - st.order_of_key(nums[i].second);
            st.insert(nums[i].second);
        }
        
        cout << ans << "\n";
    }
    return 0;
}
