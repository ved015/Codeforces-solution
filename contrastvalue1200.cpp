#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int state = 0,c = 0;;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1] && state != 1){
                c++;
                state = 1;
            }
            else if(nums[i-1] < nums[i] && state != -1){
                c++;
                state = -1;
            }
        }
        cout << c + 1 << endl;
    }
    return 0;
}