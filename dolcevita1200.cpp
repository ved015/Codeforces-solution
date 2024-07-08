#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,x;
        cin >> n >> x;
        vector<long long> shop(n);
        for(long long i = 0; i < n; i++){
            cin >> shop[i];
        }
        sort(shop.begin(),shop.end());
        vector<long long> prefix(n);
        long long sum = 0;
        for(long long i = 0; i < n; i++){
            prefix[i] = shop[i] + sum;
            sum += shop[i];
        }

        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(x >= prefix[i]){
                int val = ((x-prefix[i])/(i+1)) + 1;
                ans += val;
            }
        }
        cout << ans << endl;
    }
    return 0;
}