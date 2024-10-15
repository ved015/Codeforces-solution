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
        int a,b,k;
        cin >> a >> b >> k;
        map<int,int> m1,m2;
        for(int i = 0; i < k; i++){
            int a;
            cin >> a;
            m1[a]++;
        }
        for(int i = 0; i < k; i++){
            int a;
            cin >> a;
            m2[a]++;
        }
        ll ans = ((ll)k*(k-1))/2;
        for(auto it : m1){
            int val = it.second;
            ans -= ((ll)val*(val-1))/2;
        }
        for(auto it : m2){
            int val = it.second;
            ans -= ((ll)val*(val-1))/2;
        }
        cout << ans << endl;
    }
    return 0;
}