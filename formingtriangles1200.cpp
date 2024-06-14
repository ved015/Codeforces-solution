#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector <long long> arr(n);
        unordered_map<long long,long long> freq;
        for(long long i = 0; i < n; i++){
            cin >> arr[i];
            freq[arr[i]]++;
        }


        long long ans = 0;
        long long runningsum = 0;
        for(auto it : freq){
            long long num = it.second;
            if(num >= 3){
                ans += (num*(num-1)*(num-2))/6;
            }
            if(num >= 2){
                ans += num*(num-1)*runningsum/2;
            }
            runningsum += num;
        }
        cout << ans << endl;
    }
    return 0;
}