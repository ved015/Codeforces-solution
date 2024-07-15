#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
void primefactors(long long num, map<long long, long long>& m) {
    for (long long i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            m[i]++;
            num /= i;
        }
    }
    if (num > 1) {
        m[num]++;
    }
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> nums(n);
        for(long long i = 0; i<n; i++){
            cin >> nums[i];
        }
        map<long long,long long> m;
        for(auto it : nums){
            primefactors(it,m);
        }
        bool flag = true;
        for(auto it : m){
            if(it.second%n != 0){
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}