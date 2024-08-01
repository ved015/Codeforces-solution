#include <iostream>
#include <string>
#include <vector>
// #include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> prefix(n, 0);

    long long i = 0;
    while (i < n){
        if (s[i] == 'v') {
            long long count = 0;
            while (i < n && s[i] == 'v') {
                count++;
                i++;
            }
            if (count >= 2) {
                prefix[i - 1] = count - 1;
            }
        }
        else i++;
    }
    long long leftsum = 0, rightsum = 0;
    for(auto it : prefix){
        rightsum += it;
    }

    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        leftsum += prefix[i];
        rightsum -= prefix[i];
        if (s[i] == 'o') {
            ans += leftsum * rightsum;
        }
    }
    cout << ans << endl;
    return 0;
}
