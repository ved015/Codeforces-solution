#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

int main(){
    int t = 1;
    while(t--){
        ll n;
        cin >> n;
        ll sum = 0;
        for(int i = 0; i < n - 1; i++){
            int a;
            cin >> a;
            sum += a;
        }
        cout << (ll)(n*(n+1))/2 - sum << endl;
    }
    return 0;
}