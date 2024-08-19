// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<map>
// #include<set>
// #include<string>
// using namespace std;
// int dist(string &s,int start){
//     int val = 0;
//     int idx = start;
//     for(int i = 0; i < s.size(); i++){
//         if(s[i] == '*'){  
//             val += abs(i - idx);
//             idx++;
//         }   
//     }
//     return val;
// }
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         string sheep;
//         cin >> sheep;
//         int total = 0;
//         for(auto &it : sheep){
//             if(it == '*') total++;
//         }
//         total--;
//         // {sheep_count,{start,end}}
//         vector<pair<int,pair<int,int> > > optimal;
//         int l = 0;
//         int count = 0;
//         for(int r = 0; r < sheep.size(); r++){
//             if(sheep[r] == '*') count++;
//             if(r >= total){
//                 optimal.push_back(make_pair(count,make_pair(l,r)));
//                 if(sheep[l] == '*') count--;
//                 l++;
//             }
//         }
//         sort(optimal.rbegin(),optimal.rend());
//         // for(auto it : optimal){
//         //     cout << it.first << " " << it.second.first << " " << it.second.second << endl;
//         // }
//         int maxi = optimal[0].first;
//         if(maxi == 0){
//             cout << 0 << endl;
//             continue;
//         }
//         int ans = INT_MAX;
//         for(auto it : optimal){
//             if(it.first >= maxi - total){
//                 ans = min(ans,dist(sheep,it.second.first));
//             }
//             else break;
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string sheep;
        cin >> sheep;

        vector<int> positions;
        for(int i = 0; i < n; i++){
            if(sheep[i] == '*') positions.push_back(i);
        }

        int m = positions.size();
        if(m == 0){
            cout << 0 << endl;
            continue;
        }

        int med = m / 2;
        int median = positions[med];

        long long moves = 0;
        for(int i = 0; i < m; i++){
            moves += abs(positions[i] - (median - med + i));
        }

        cout << moves << endl;
    }
    return 0;
}
