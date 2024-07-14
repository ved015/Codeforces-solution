#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> nums(n);
        for(int i = 0; i <n; i++){
            cin >> nums[i];
        }
        map<long long,long long> m;
        m[0] = 1;
        bool flag = false;
        long long evensum = 0,oddsum = 0;
        for(int i = 1; i<=n; i++){
            if(i%2 == 0) evensum += nums[i-1];
            else oddsum += nums[i-1];
            m[evensum - oddsum]++;
            if(m[evensum - oddsum] > 1){
                flag = true;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}