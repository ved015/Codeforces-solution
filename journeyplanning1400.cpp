#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    unordered_map<int, ll> groupSums;
    for(int i = 0; i < n; i++) {
        int key = i - nums[i];
        groupSums[key] += nums[i];
    }
    
    ll result = 0;
    for(auto &entry : groupSums) {
        result = max(result, entry.second);
    }
    
    cout << result << endl;
    return 0;
}
