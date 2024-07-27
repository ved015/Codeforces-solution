#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int> > caves;
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            vector<int> temp(m);
            int maxi = INT_MIN; 
            for(int j = 0; j < m; j++){
                cin >> temp[j];
                maxi = max(maxi,temp[j] + 1 - j);
            }
            caves.push_back(make_pair(maxi,m));
        }

        sort(caves.begin(),caves.end());

        int initial_power = 0;
        int current_power = 0;
        
        for (const auto& cave : caves) {
            int required_power = cave.first;
            int monsters_in_cave = cave.second;
            
            if (current_power < required_power) {
                initial_power += (required_power - current_power);
                current_power = required_power;
            }
            
            current_power += monsters_in_cave;
        }
        
        cout << initial_power << endl;
    }
    return 0;
}