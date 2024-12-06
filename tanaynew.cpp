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
        string n;
        cin >> n;
        int two = 0,three = 0;
        ll sum = 0;
        for(auto it : n){
            if(it == '2') two++;
            if(it == '3') three++;
            sum += it - '0';
        }
        // at each operation either 2(earlier it was two it became 4 so net 2 added) will be added or 
        // 6(went from 3 to 9 so net 6) will be added
        // so let the number after squaring digit has sum x so
        // x - sum = some combination of 2 and 6
        // 2*x1 + 6*x2 = y
        // so if we use two nested loops to find such combination of x1 and x2
        // then worst case time complexity will be n^2/4
        bool flag = false;
        for(int i = 0; i <= two; i++){
            for(int j = 0; j <= three; j++){
                ll newsum = sum + 2*i + 6*j;
                if(newsum%9 == 0) flag = true;
            }
            if(flag) break;
        }
        
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}