#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> nums(n);
        unordered_map<ll,ll> m;
        for(ll i = 0; i < n; i++){
            cin >> nums[i];
            m[nums[i]] = i + 1;
        }
        ll maxsum = (2*n) - 1;
        ll minsum = 3;
        ll count = 0;
        sort(nums.begin(),nums.end());

        for(ll i =  0; i < n; i++){
            if(nums[i] > maxsum) break;
            for(ll j = i + 1; j < n; j++){
                ll val = nums[i]*nums[j];
                if(val > maxsum) break;
                else if(val < minsum) continue;
                else{
                    ll a = m[nums[i]];
                    ll b = m[nums[j]];
                    if(a + b == val){
                        count++;
                    }
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}