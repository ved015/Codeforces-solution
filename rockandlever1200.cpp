#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
long long setbitbinary(long long a){
    vector<long long> ans;
    while(a > 0){
        ans.push_back(a%2);
        a = a/2;
    }
    reverse(ans.begin(),ans.end());
    long long binarysize = ans.size();
    for(long long i = 0; i < binarysize; i++){
        if(ans[i] == 1) return ans.size() - i;
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> arr(n);
        unordered_map<long long,long long> m;
        for(long long i = 0; i < n; i++){
            cin >> arr[i];
            long long pos = setbitbinary(arr[i]);
            m[pos]++;
        }
        long long ans = 0;
        for(auto it : m){
            if(it.second >= 2) ans += (it.second*(it.second-1))/2;
        }
        cout << ans << endl;
    }
    return 0;
}