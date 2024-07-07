#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n >> s;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        vector<int> prefix(n+1);
        int sum = 0;
        for(int i = 0; i < n; i++){
            prefix[i] = sum;
            sum += nums[i];
        }
        prefix[n] = sum;

        int i = 0,j = 0;
        int ans = INT_MAX;
        while(j < nums.size()){
            if(prefix[j+1] - prefix[i] == s){
                ans = min(ans,n - 1 - j + i); 
            }
            while(prefix[j+1] - prefix[i] > s){
                i++;
            }
            j++;
        }
        if(sum == s) cout << 0 << endl;
        else if(sum < s) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}