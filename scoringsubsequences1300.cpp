#include<iostream>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        priority_queue<int> p;
        
        for (int i = 0; i < n; i++)
        {
            p.push(-1 * a[i]);
            while (p.size() > (-1 * p.top()))
                p.pop();
            int t1 = p.size();
            cout << min(INT_MAX, t1) << " ";
        }
        cout << endl;
    }
    return 0;
}
