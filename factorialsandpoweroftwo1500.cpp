#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

bool solve(int idx, ll sum,int count,ll n, vector<ll> &nums,int &minlen) {
    if(sum > n) return false;
    if (sum == n) {
        minlen = min(count, minlen);
        return true;
    }
    if (idx >= nums.size()) return false; 

    bool take = solve(idx + 1,sum + nums[idx],count + 1, n, nums,minlen);

    bool nottake = solve(idx + 1,sum,count, n, nums,minlen);

    return take || nottake;
}
int main(){
    int t;
    cin >> t;
    set<ll> s;

    int val = 0;
    ll temp = 0;
    while(temp <= 1e12){
        temp = (ll)(1LL << val);
        s.insert(temp);
        val++;
    }
    ll fac = 1;
    ll num = 2;
    while(fac <= 1e12){
        s.insert(fac);
        fac = fac * num;
        num++;
    }
    vector<ll> nums;
    for(auto it : s){
        nums.push_back(it);
    }
    while(t--){
        ll n;
        cin >> n;
        int minlen = 80;
        if(solve(0,0,0,n,nums,minlen)){
            cout << minlen << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}