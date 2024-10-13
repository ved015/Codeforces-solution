#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;
ll helper(map<int,vector<int> > &pos){
    ll weirdsum = 0;
    for(auto it : pos){
        vector<int> nums = it.second;
        sort(nums.begin(),nums.end());

        int n = nums.size();
        if (n <= 1) continue;

        ll tsum = 0,tempsum = 0;
        for(auto num : nums) tsum += num;

        for(int i = 0; i < n; i++){
            tempsum += nums[i];
            ll contribution = (tsum - tempsum) - (ll)(n - i - 1) * nums[i];
            weirdsum += contribution;
        }
    }
    return weirdsum;
}
int main(){
    while(true){
        int n,m;
        cin >> n >> m;
        map<int,vector<int> > posrow;
        map<int,vector<int> > poscol;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int value;
                cin >> value;
                posrow[value].push_back(i);
                poscol[value].push_back(j);
            }
        }
        // 1 -> (0,0) (0,1) (1,1) (1,2) (2,2) (2,3)
        // 0 1 2 3 4 5
        // (tsum) - (n - i - 1)*nums[i];

        // 2 -> (0,2) (0,3) (1,0) (1,3) (2,0) (2,1)
        // 2 3 1 4 2 3
        // 1 2 2 3 3 4
        ll val1 = helper(posrow);
        ll val2 = helper(poscol);
        ll total = val1 + val2;
        cout << total;
        break;
    }
    return 0;
}