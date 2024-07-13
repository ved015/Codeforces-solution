#include <iostream>
using namespace std;
int solve(int n,int k){
    if(n%2 == 0){
        int val = k%n;
        if(val == 0) val = n;
        return val;
    }
    else{
        k--;
        int rem = n/2;
        return 1 + (k + (k/rem))%n;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        cout << solve(n,k) << endl;
    }
    return 0;
}
