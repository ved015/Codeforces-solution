#include<iostream>
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
        int val = nums[0];
        int count = 0;
        int mini = INT_MAX;
        for(int i = 0; i<n; i++){
            if(nums[i] == val){
                count++;
            }
            else{
                mini = min(mini,count);
                count = 0;
            }
        }
        mini = min(mini,count);
        if(mini == nums.size()) cout << -1 << endl;
        else cout << mini << endl;
    }
    return 0;
}