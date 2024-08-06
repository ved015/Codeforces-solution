#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool solve(string& s,string& t) {
    int m = s.length(), n = t.length();
    int j = 0;
    for (int i = 0; i < m && j < n; i++) {
        if (s[i] == '?') {
            s[i] = t[j];
            j++;
        } else if (s[i] == t[j]) {
            j++;
        }
    }
    
    if (j == n) {
        for (char& c : s) {
            if (c == '?') {
                c = 'z';
            }
        }
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        string s, t;
        cin >> s >> t;
        
        if (solve(s, t)) {
            cout << "YES" << endl;
            cout << s << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
