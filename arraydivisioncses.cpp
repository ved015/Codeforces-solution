#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool is_possible(const vector<ll> &arr, const int k, ll max_sum) {
	int subarr_count = 0;
	// sum of the current subarray
	ll cur_sum = 0;

	for (const int &x : arr) {
		if (x > max_sum) { return false; }

		if (cur_sum + x > max_sum) {
			subarr_count++;
			cur_sum = 0;
		}
		cur_sum += x;
	}
	if (cur_sum > 0) { subarr_count++; }

	return subarr_count <= k;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (ll &i : arr) { cin >> i; }

	ll l = *max_element(begin(arr), end(arr));
	ll r = accumulate(begin(arr), end(arr), 0LL);
	while (l < r) {
		ll mid = (l + r) / 2;
		if (is_possible(arr, k, mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << l << endl;
}