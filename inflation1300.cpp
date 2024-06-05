#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n,k;
        cin >> n >> k;
        vector<long long int> a(n);
        for(long long int i = 0; i < n; i++){
            cin >> a[i];
        }
        long long int sum = 0,prefix = 0;
        for(long long int i = 1; i<n; i++){
            prefix += a[i-1];
            if(a[i]*100 <= (prefix+sum)*k){
                continue;
            }
            else{
                long long diff = a[i]*100 - (prefix+sum)*k;
                sum += diff/k;
                if(diff%k != 0){
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
}