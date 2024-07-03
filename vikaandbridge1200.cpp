#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> planks(n);
        unordered_map<int,vector<int> > m;
        for(int i = 0; i < n; i++){
            cin >> planks[i];
        }
        for(int i = 1; i <=k; i++){
            m[i].push_back(0);
        }
        for(int i = 0; i < n; i++){
            m[planks[i]].push_back(i+1);
        }
        for(auto it : m){
            m[it.first].push_back(n+1);
        }

        for(auto it : m){
            int pos1 = 0,pos2 = 0;
            int maxi = INT_MIN;
            for(int i = 1; i < it.second.size(); i++){
                if(it.second[i] - it.second[i-1] > maxi){
                    maxi = it.second[i] - it.second[i-1];
                    pos1 = it.second[i-1];
                    pos2 = it.second[i];
                }
            }
            m[it.first].push_back((pos1 + pos2)/2);
        }

        int ans = INT_MAX;

        for(auto &it : m){
            int maxi = INT_MIN;
            sort(it.second.begin(),it.second.end());
            for(int i = 1; i < it.second.size(); i++){
                maxi = max(it.second[i] - it.second[i-1],maxi);
            }
            ans = min(ans,maxi);
        }

        cout << ans - 1 << endl;
    }
    return 0;
}