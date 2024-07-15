#include <iostream>
#include <string>
using namespace std;

int main(){
    string n;
    cin >> n;
    if (n[0] - '0' != 9 && n[0] - '0' > 4) {
        int num = n[0] - '0';
        n[0] = 9 - num + '0';
    }

    for (int i = 1; i < n.size(); i++) {
        long long num = n[i] - '0';
        if (num > 4) {
            n[i] = 9 - num + '0';
        }
    }

     cout << stoll(n) << endl;

    return 0;
}
