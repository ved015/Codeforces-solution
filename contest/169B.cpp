#include <iostream>
#include <algorithm>
#include<map>
#include<set>
// #include<bits/stdc++.h>
using namespace std;

int solve(int l, int r, int L, int R,map<int,int> &m1,map<int,int> &m2) {
    set<pair<int,int> > s;
    for(int i = l; i <= r; i++){
        if(m1.find(i+1) != m1.end()){
            s.insert(make_pair(i,i+1));
        }
    }
    for(int i = L; i <= R; i++){
        if(m2.find(i+1) != m2.end()){
            s.insert(make_pair(i,i+1));
        }
    }
    if(s.size() == 0) return 1;
    return s.size();
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int l, r, L, R;
        cin >> l >> r;
        cin >> L >> R;
        map<int,int> m1,m2;
        for(int i = L ; i<=R; i++){
            m1[i]++;
        }
        for(int i = l; i<=r; i++){
            m2[i]++;
        }
        cout << solve(l, r, L, R,m1,m2) << endl;
    }
    
    return 0;
}