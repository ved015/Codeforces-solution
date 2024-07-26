#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;


long long ans(int n, int x) {
    long long result = 0;
    
    for (int a = 1; a <= min(n, x - 2); ++a) {
        for (int b = 1; b <= min(n / a, x - a - 1); ++b) {
            int max_c = min(x - a - b, (n - a * b) / (a + b));
            if (max_c > 0) {
                result += max_c;
            }
        }
    }
    
    return result;
}

int main() {    
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
        cout << ans(n, x) << '\n';
    }
    
    return 0;
}