#include<iostream>
using namespace std;
int solve(int n,int k){
    if(n == 1) return 0;
    int i = k;
    int count = 1;
    while(i < n){
        i += k - 1;
        count++;
    }
    return count;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        cout << solve(n,k) << endl;
    }
    return 0;
}