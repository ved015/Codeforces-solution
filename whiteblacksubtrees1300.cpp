#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<vector<int> > &adjls, vector<char> &colors, int &black, int &white) {
    if (colors[node] == 'B') black++;
    else white++;
    for (int child : adjls[node]) {
        dfs(child, adjls, colors, black, white);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> parents(n-1);
        vector<char> colors(n);
        for(int i = 0; i < n-1; i++){
            cin >> parents[i];
        }
        for(int i = 0; i < n; i++){
            cin >> colors[i];
        }

        vector<vector<int> > adjls(n);
        for(int j = 0; j < n-1; j++){
            adjls[parents[j] - 1].push_back(j + 1);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int black = 0, white = 0;
            dfs(i, adjls, colors, black, white);
            if (black == white) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
