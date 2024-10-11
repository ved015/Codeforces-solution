#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll diff = 0;
        for (ll k = 0; (1ll << k) <= n; k++) {
            diff += (n / (1ll << k));
        }
        cout << diff << endl;
    }
    return 0;
}