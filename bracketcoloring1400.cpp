#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

int helper(string bc, vector<int> &ans) {
    stack<pair<char, int> > s;
    for(int i = 0; i < bc.size(); i++) {
        if(s.empty()) s.push(make_pair(bc[i], i));
        else {
            char ch = s.top().first;
            int idx = s.top().second;
            if(ch == '(' && bc[i] == ')') {
                s.pop();
                ans[i] = 1;
                ans[idx] = 1;
            } else {
                s.push(make_pair(bc[i], i));
            }
        }
    }
    if(s.size() % 2 != 0) return -1;
    int lb = 0, rb = 0;
    while(!s.empty()) {
        char ch = s.top().first;
        if(ch == '(') lb++;
        else rb++;
        s.pop();
    }
    if(lb != rb) return -1;
    set<int> temp;
    for(auto it : ans) temp.insert(it);
    if(temp.size() == 1) return 1;
    return 2;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string bc;
        cin >> bc;
        vector<int> ans(n, -1);
        
        int value1 = helper(bc, ans);
        
        if(value1 == 2) {
            reverse(bc.begin(), bc.end());
            vector<int> temp(n, -1);
            int value2 = helper(bc, temp);
            
            if(value2 == 1) {
                cout << 1 << endl;
                for(int i = 0; i < n; i++) cout << 1 << " ";
                cout << endl;
                continue;
            }
        }
        
        if(value1 == -1) {
            cout << -1 << endl;
        } else if(value1 == 1) {
            cout << 1 << endl;
            for(int i = 0; i < n; i++) cout << 1 << " ";
            cout << endl;
        } else {
            cout << 2 << endl;
            for(int i = 0; i < n; i++) {
                if(ans[i] == 1) cout << 1 << " ";
                else cout << 2 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
