#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int> > nums;
        for(int i = 0; i < n; i++){
            int l,r;
            cin >> l >> r;
            nums.push_back(make_pair(l,r));
        }     
        sort(nums.begin(),nums.end());

        pair<int,int> g1 = make_pair(nums[0].first,nums[0].second);
        pair<int,int> g2 = make_pair(INT_MAX,-1);

        vector<int> ans;
        ans.push_back(1);

        for(int i = 1; i < n; i++){
            if(nums[i].first > g1.second && nums[i].first >= g2.second){
                g2.first = min(g2.first,nums[i].first);
                g2.second = max(g2.second,nums[i].second);
                ans.push_back(2);
            }
            if(nums[i].first <= g1.second){
                g1.second = max(g1.second,nums[i].second);
                ans.push_back(1);
            }
        }

        set<int> s;
        for(auto it : ans) s.insert(it);
        if(s.size() < 2){
            cout << -1 << endl;
            continue;
        }
        for(auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}