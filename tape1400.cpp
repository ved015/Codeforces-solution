#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
	ll maxi = nums[n-1] - nums[0] + 1;
	vector <ll> gaps;
	for(int i = 0; i < n - 1; i++){
	    gaps.push_back(nums[i+1] - nums[i] - 1);
	}
	
	sort(gaps.rbegin(), gaps.rend());
	
	ll sub = 0;
	for(int i = 0; i < k - 1; i++){
	    sub += gaps[i];
	}
	
	ll answer = maxi - sub;
	cout << answer;
    return 0;
}