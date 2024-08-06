#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,s,m;
        cin >> n >> s >> m;
        vector<pair<int,int> > pairs;
        for(int i = 0; i < n; i++){
            int l,r;
            cin >> l >> r;
            pairs.push_back(make_pair(l,r));
        }
        if(pairs[0].first >= s){
            cout << "YES" << endl;
            continue;
        }
        if(m - pairs[pairs.size() - 1].second >= s){
            cout << "YES" << endl;
            continue;
        }
        bool flag = false;
        for(int i = 1; i < n; i++){
            if(pairs[i].first - pairs[i-1].second >= s){
                flag = true;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}