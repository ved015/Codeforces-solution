#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<long long> nums(n);
    unordered_map<long long,long long> m;
    long long total = 0;
    for(long long i = 0; i < n; i++){
        cin >> nums[i];
        m[nums[i]]++;
        total += nums[i];
    }

    vector<long long> ans;
    for(long long i = 0; i < n; i++){
        m[nums[i]]--;
        if(m[nums[i]] == 0) m.erase(nums[i]);
        if((total - nums[i]) % 2 == 0 && m.find((total - nums[i]) / 2) != m.end()){
            ans.push_back(i + 1);
        }
        m[nums[i]]++;
    }
    cout << ans.size() << endl;
    for(long long i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}