#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

int main(){
    int t = 1;
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
        bool flag = true;
        priority_queue<pair<int,int> > pq;
        for(int i = 0; i < n; i++){
            if(pq.empty()){
                pq.push(make_pair(nums[i].first,nums[i].second));
            }
            else if(pq.size() == 1){
                auto it = pq.top();
                int r = it.second;
                if(nums[i].first > r){
                    pq.pop();
                    pq.push(make_pair(nums[i].first,nums[i].second));
                }
                else pq.push(make_pair(nums[i].first,nums[i].second));
            }
            else{
                int l1 = pq.top().first;
                int r1 = pq.top().second;
                pq.pop();
                int l2 = pq.top().first;
                int r2 = pq.top().second;
                pq.pop();
                if(nums[i].first <= min(r1,r2)) flag = false;
                else if(nums[i].first > max(r1,r2)) pq.push(make_pair(nums[i].first,nums[i].second));
                else{
                    pq.push(make_pair(nums[i].first,nums[i].second));
                    if(r2 > r1) pq.push(make_pair(l2,r2));
                    else pq.push(make_pair(l1,r1));
                }
            }
        }
        string temp = (flag) ? "YES" : "NO";
        cout << temp << endl;
    }
    return 0;
}