#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int sizeofs = s.size();

        if(sizeofs < 3){
            cout << "NO" << endl;
            continue;
        }
        if(s.size() == 3 && (s[0] == '1' && s[1] == '0' && s[2] != '0' && s[2] != '1')){
            cout << "YES" << endl;
            continue;
        }
        if(s.size() > 3 && (s[0] == '1' && s[1] == '0' && s[2] != '0')){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}