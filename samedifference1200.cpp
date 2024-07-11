#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> nums(n);
        for(long long i = 0; i < n; i++){
            cin >> nums[i];
        }
        unordered_map<long long,long long> m; 
        for(long long i = 0; i < n; i++){
            long long val = nums[i] - (i + 1);
            m[val]++;
        }
        long long count = 0;
        for(auto it : m){
            count += (it.second*(it.second-1))/2;
        }

        cout << count << endl;
    }
    return 0;
}