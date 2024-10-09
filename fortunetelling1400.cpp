#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;
string solve(ll n,ll x,ll y,vector<ll> &nums){
    ll alice = x;
    ll bob = x + 3;
    // see plus will only increase and xor can increase/decrease depends on a[i]
    int odd = 0;
    for(auto it : nums){
        if(it&1) odd++;
    }
    if(odd%2 == 0){
        if(x%2 == y%2) return "Alice";
        else return "Bob";
    }
    if(x%2 != y%2) return "Alice";
    return "Bob";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,x,y;
        cin >> n >> x >> y;
        vector<ll> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        } 
        cout << solve(n,x,y,nums) << endl;
    }
    return 0;
}