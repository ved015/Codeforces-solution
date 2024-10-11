#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;
vector<int> tobinary(int n){
    vector<int> ans;
    while(n > 0){
        ans.push_back(n%2);
        n = n/2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    ll mod = 1e9 + 7;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        map<int,int> m;
        for(auto it : nums){
            vector<int> temp = tobinary(it);
            for(int i = 0; i < temp.size(); i++){
                if(temp[i] == 1) m[temp.size() - i - 1]++;
            }
        }
        set<int> bits;
        for(auto it : m){
            if(it.second == n) bits.insert(it.first);
        }
        int allowed = 0;
        for(auto it : nums){
            bool flag = true;
            vector<int> temp = tobinary(it);
            for(int i = 0; i < temp.size(); i++){
                if(temp[i] == 1 && bits.find(temp.size() - i - 1) == bits.end()) flag = false;
            }
            if(flag) allowed++;
        }
        ll ans = 0;
        ans += ((ll)allowed * (allowed - 1)) % mod;
        int rem = n - 2;
        for(int i = rem; i >= 1; i--){
            ans = (ans*i)%mod;
        }
        cout << ans << endl;
    }
    return 0;
}