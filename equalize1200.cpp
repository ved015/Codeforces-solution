#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
#define ll long long int
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        set<ll> s;
        for(ll i = 0; i<n; i++){
            ll a;
            cin >> a;
            s.insert(a);
        }

        vector<ll> nums;
        for(auto it : s){
            nums.push_back(it);
        }
        
        ll maxi = -1;
        for(ll i = 0; i < nums.size(); i++) {
            int start = i;
            int end = nums.size() - 1;
            while(start <= end){
                ll mid = start + (end - start) / 2;
                if(nums[mid] - nums[i] < n){
                    maxi = max(maxi, mid - i + 1);
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        cout << maxi << endl;
        
    }
    return 0;
}