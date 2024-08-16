#include<iostream>
using namespace std;
long long mod = 1e9 + 7;
vector<vector<vector<long long> > > dp;

long long solve(long long index, long long prev, long long count, long long k, vector<long long> &nums) {
    long long n = nums.size();
    
    if (count > k) return 0;    
    if (index == n) {
        return (count == k) ? 1 : 0;
    }

    if (dp[index][prev][count] != -1) {
        return dp[index][prev][count];
    }

    long long res = 0;

    if (nums[index] % nums[prev] == 0) {
        res += solve(index, index, count + 1, k, nums);
        res %= mod;
    }
    res += solve(index + 1, prev, count, k, nums);
    res %= mod;

    return dp[index][prev][count] = res;
}

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> nums(n);

    for (long long i = 1; i <= n; i++) {
        nums[i - 1] = i;
    }

    dp.assign(n, vector<vector<long long> >(n, vector<long long>(k + 1, -1)));
    long long ans = solve(0,0, 0, k, nums);
    cout << ans << endl;
    return 0;
}
