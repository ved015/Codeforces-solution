#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long get(long long x) {
    return x * (x + 1) / 2;
}
long long bs(vector<long long>&arr,long long x){
          long long i = 0, j = arr.size() - 1;
            while(i <= j){
                long long mid = (i + j) / 2;
                if(arr[mid] == x){
                    return mid + 1;
                }
                if(arr[mid] > x){
                    j = mid - 1;
                }
                else {
                    i = mid + 1;
                }
            }
            return i + 1;
}
int main(){
    vector<long long> arr;
    long long val = 1e9;
    long long ans = 0;
    for(long long i = 1; i <= val; i++){
        ans += i;
        arr.push_back(ans);
    }

    long long get_val = get(val);

    long long t;
    cin >> t;
    while(t--){
        long long k, x;
        cin >> k >> x;

        if (x <= get_val) {
            cout << bs(arr,x) << endl;
        } else {
            x -= get_val;
            cout << arr.size() + bs(arr,x) << endl;
        }
    }
    return 0;
}
