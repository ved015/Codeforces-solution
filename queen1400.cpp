// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<map>
// #include<set>
// #include<string>
// using namespace std;
// typedef long long ll;

// int main(){
//     int n;
//     cin >> n;
//     vector<int> res(n),parent(n,-1);
//     for(int i = 0; i < n; i++){
//         int p,c,root;
//         cin >> p >> c;
//         if(p != -1) parent[i] = p - 1;
//         res[i] = c;
//     }
//     vector<int> ans;
//     for(int i = 0; i < res.size(); i++){
//         bool flag = true;
//         if(res[i] == 1){
//             for (int j = 0; j < n; j++) {
//                 if (parent[j] == i && res[j] == 0) {
//                     flag = false;
//                 }
//             }
//             if(flag){
//                 ans.push_back(i + 1);
//                 res[i] = -1;
//             }
//         }
//     }
//     for(auto it : ans){
//         cout << it << " ";
//     }
//     if(ans.size() == 0) cout << -1 << endl;
//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> res(n), parent(n, -1);
    vector<bool> cd(n, false);

    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        if (p != -1) {
            parent[i] = p - 1;
        }
        res[i] = c;
    }

    for (int i = 0; i < n; i++) {
        if (res[i] == 0 && parent[i] != -1) {
            cd[parent[i]] = true;
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (res[i] == 1 && !cd[i]) {
            ans.push_back(i + 1);
        }
    }
    for(auto it : ans){
        cout << it << " ";
    }
    if(ans.size() == 0) cout << -1 << endl;
    return 0;
}
