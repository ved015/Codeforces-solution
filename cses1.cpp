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
        cout << n << " ";
        while(n != 1){
            if(n%2 == 0) n = n/2;
            else n = 3*n + 1;
            cout << n << " ";
        }

    }
    return 0;
}