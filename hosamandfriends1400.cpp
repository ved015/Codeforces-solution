#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<unordered_set>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        set<pair<int,int> > nums;
        for (int i = 0; i < m; i++) {
            int f1, f2;
            cin >> f1 >> f2;
            if(f1 < f2) swap(f1,f2);
            nums.insert(make_pair(f1,f2));
        }
        long long ans = 0;
        for(int i = 1; i <=n-1; i++){
            if(s.find(make_pair(i,i+1)) != s.end){
                continue;
            }
            else{
                
            }
        }

        cout << ans << endl;
    }
    return 0;
}
