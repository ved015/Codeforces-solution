#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int count = 0;
        for (char it : s){
            if(it == '0') count++;
        }
        if(count == 1){
            cout << "BOB" << endl;
        }
        else if(count & 1){
            cout << "ALICE" << endl;
        }
        else{
            cout << "BOB" << endl;
        }
    }
    return 0;
}
