#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k--; 

        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        int cow = nums[k];
        int count = 0,index = 0;

        swap(nums[k],nums[0]);
        for(int i = 1; i<n; i++){
            if(nums[i] < cow){
                count++;
            }
            else{
                break;
            }
        }
        swap(nums[0],nums[k]);
        for (int i = 0; i < k; i++){
            if (nums[i] > nums[k])
            {
                swap(nums[i], nums[k]);
                k = i;
                break;
            }
        }
        int ans = 0;
        if (k != 0) ans++;
        for (int i = k + 1; i < n; i++)
        {
            if (nums[i] < nums[k])
                ans++;
            else
                break;
        }
        
    cout << max(count,ans) << endl;
    }
    return 0;
}
