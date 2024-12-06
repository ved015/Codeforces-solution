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
        int n;
        cin >> n;
        if(n == 2 || n == 3) cout << "NO SOLUTION" << endl;
        else{
            for(int i = 2; i <= n; i+=2){
                cout << i << " ";
            }
            for(int i = 1; i <= n; i+=2){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}