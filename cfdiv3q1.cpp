#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = n/4;
        int rem = n%4;
        ans += rem/2;
        cout << ans << endl;
    }
    return 0;
}