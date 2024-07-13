#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a,b;
        cin >> a;
        cin >> b;
        vector<pair<int,int> > pairs;
        vector<int> nums;
        int zero = 0,one = 0;
        vector<pair<int,int> > prefix(n);
        for(int i = 0; i < n; i++){
            if(a[i] == '0') zero++;
            else one++;
            prefix[i] = make_pair(zero,one);

            if(a[i] != b[i]){
                nums.push_back(i);
            }
            else{
                if(nums.size() != 0){
                    pairs.push_back(make_pair(nums[0] - 1,nums[nums.size()-1]));
                    nums.clear();
                }
            }
        }
        if(nums.size() != 0) pairs.push_back(make_pair(nums[0] - 1,nums[nums.size()-1]));
        if(pairs.size() == 0) cout << "YES" << endl;
        else{
            bool flag = true;
            for(int i = 0; i < pairs.size(); i++){
                int startindex = pairs[i].first;
                int endindex = pairs[i].second;
                if((startindex != -1 && prefix[startindex].first != prefix[startindex].second) || prefix[endindex].first != prefix[endindex].second){
                    flag = false;
                    break;
                }
            }
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}