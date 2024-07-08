#include<iostream>
#include<vector>
#include<algorithm>
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
        if(nums[n-2] < 0 && nums[n-1] < 0){
            vector<int> temp = nums;
            sort(temp.begin(),temp.end());
            if(temp == nums) cout << 0 << endl;
            else cout << -1 << endl;
        }
        else if(nums[n-2] <= nums[n-1]){
            cout << n - 2 << endl;
            for(int i = 0; i < n-2; i++){
                cout << i + 1 << " " << n-1 << " " << n << endl;
            }
        }
        else cout << -1 << endl;
    }
    return 0;
}