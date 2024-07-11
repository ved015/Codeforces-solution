#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

string generateStrings(int length,unordered_set<string> &substrings) {
    string current(length, 'a');
    while (true) {
        if(substrings.find(current) == substrings.end()){
            return current;
        }
        int pos = length - 1;
        while (pos >= 0 && current[pos] == 'z') {
            current[pos] = 'a';
            --pos;
        }
        if (pos < 0) break;
        current[pos]++;
    }
    return "";
}

string findMEX(const string& s) {
    unordered_set<string> substrings;
    
    for (int i = 0; i < s.size(); ++i) {
        string temp = "";
        for (int j = i; j < s.size(); ++j) {
            temp += s[j];
            substrings.insert(temp);
        }
    }
    for (int len = 1; len <= 3; ++len) {
        string ans = generateStrings(len,substrings);
        if(ans.size() >= 1) return ans;
    }

    return "";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << findMEX(s) << endl;
    }
    return 0;
}
