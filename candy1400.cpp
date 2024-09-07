#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            freq[a]++;
        }

        vector<int> counts;
        for (auto &it : freq) {
            counts.push_back(it.second);
        }

        sort(counts.rbegin(), counts.rend());

        ll ans = 0;
        int prev = counts[0] + 1;

        for (auto it : counts) {
            if (prev > 0) {
                prev = min(prev - 1, it);
                ans += prev;
            }
        }

        cout << ans << endl;
    }
    return 0;
}

// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         map<int,int> m1,m2;
//         for(int i = 0; i < n; i++){
//             int a;
//             cin >> a;
//             m1[a]++;
//         }
//         vector<int> temp;
//         for(auto &it : m1){
//             temp.push_back(it.second);
//         }
//         for(auto it : temp){
//             m2[it]++;
//         }
//         // grp size and freq stored
//         vector<pair<int,int> > nums;
//         for(auto &it : m2){
//             nums.push_back(make_pair(it.first,it.second));
//             // cout << it.first << " " << it.second << endl;
//         }
//         // cout << "test ended" << endl;
//         sort(nums.rbegin(),nums.rend());
//         int mini = nums[0].first - nums[0].second + 1,maxi = nums[0].first;
//         vector<pair<int,int> > ans;
//         for(int i = 1; i < nums.size(); i++){
//             if(nums[i].first < mini){
//                 ans.push_back(make_pair(maxi,mini));
//                 maxi = nums[i].first;
//                 mini = maxi - nums[i].second + 1;
//             }
//             else{
//                 mini = nums[i].first - nums[i].second + 1;
//             }

//             if(mini <= 0) mini = 1;
//         }
//         ans.push_back(make_pair(maxi,mini));
//         long long val = 0;
//         // example l = 1 r = 4;
//         // so freq = 3
//         // sum of 1 2 3 4 is 10
//         // using my formula 1 * (3 + 1) = 4
//         // and 3(3 + 1) = 12 and 12/2 = 6 so 4 + 6 = 10
//         for(auto it : ans){
//             int l = it.second;
//             int r = it.first;
//             int freq = (r - l);
//             val += (l(freq + 1)) + ((freq*(freq + 1)))/2;
//         }
//         cout << val << endl;
//     }
//     return 0;
// }
// 9 - 3
// 5 - 2
// 1 - 1
// so ans should be 9 + 8 + 7 + 5 + 4 + 1 = 34
// maxi = 9 mini = 7 since 5 < 7 so in ans 9,7 is pushed and
// maxi becomes 5 and mini becomes 4 now 1 < 4 so 5,4 gets pushed
// now maxi is 1 and mini is 1 so at last 1,1 get pushed
// so in ans loop 24 + 9 + 1 = 34
// 4 - 3
// 5 - 2
// 1 - 1
// so ans should be 5 + 4 + 3 + 2 + 1 = 15
// on dry run my code will make maxi 5 mini 4
// 4 < 4 so mini = 4 - 3 + 1 = 2
// 1 < 2 so ans me push hoga (5,2) and maxi = 1 and mini = 1 - 1 + 1 = 1
// then ans me push hoga (1,1)
// so ans me ab 5,2 and 1,1 hai so formula ke acc 5,2 will become 2 * (4) + (3*4/2) = 8 + 6 = 14
// and 1,1 se 1 * 1 + 0 = 1 so 14 + 1 = 15