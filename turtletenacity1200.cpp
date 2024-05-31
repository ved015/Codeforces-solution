#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];  
        }
        sort(nums.begin(), nums.end());

        bool flag = false;
        for(int i = 1; i < n; i++){
            if(nums[i]%nums[0] != 0){
                flag = true;
                break;
            }
        }
        if(nums[1] != nums[0]) cout << "YES" << endl;
        else{
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}