#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void Buildprefix(vector<int>& nums, int n, vector<vector<int> >& prefix) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 32; j++) {
            if(nums[i] & (1 << j)) {
                prefix[i + 1][j] = prefix[i][j] + 1;
            } else {
                prefix[i + 1][j] = prefix[i][j];
            }
        }
    }
}

int andvalue(int idx, int l, vector<vector<int> >& prefix) {
    int val = 0;
    for(int i = 0; i < 32; i++) {
        int rem = prefix[idx + 1][i] - prefix[l][i];
        if(rem == idx - l + 1) val += (1 << i);
    }
    return val;   
}

int solve(int l, int k, vector<vector<int> >& prefix) {
    int s = l, e = prefix.size() - 2;
    int result = -1;
    while(s <= e) {
        int mid = s + (e - s) / 2;
        int value = andvalue(mid, l, prefix);
        if(value >= k) {
            result = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<vector<int> > prefix(n + 1, vector<int>(32, 0));
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Buildprefix(nums, n, prefix);

        int q;
        cin >> q;
        vector<int> ans;
        for(int i = 0; i < q; i++) {
            int l, k;
            cin >> l >> k;
            int val = solve(l - 1, k, prefix);
            if(val == -1) ans.push_back(-1);
            else ans.push_back(val + 1);
        }
        for(auto& it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
