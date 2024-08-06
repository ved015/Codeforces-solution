#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

const int MAX_VAL = 200000;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> prefix(MAX_VAL + 1, 0);
    
    for (int i = 1; i <= MAX_VAL; ++i) {
        int n = i;
        int division = 0;
        while(n > 0){
            n = n/3;
            division++;
        }
        prefix[i] = prefix[i-1] + division;
    }
    
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int extra = 0;
        int val = l;
        while(val > 0){
            val = val/3;
            extra++;
        }
        cout << prefix[r] - prefix[l-1] + extra << endl;
    }

    return 0;
}