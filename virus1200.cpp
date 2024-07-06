#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        vector<long long> v(m);
        for(int i = 0; i < m; i++){
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        vector<int> diff;
        for(int i = 0; i < m-1; i++) diff.push_back(v[i+1] - v[i] - 1);
        diff.push_back(v[0] + n - v[m-1] - 1);
        int tmr = 0;
        int safe = 0;
        sort(diff.begin(),diff.end(),greater<int>());
        for(int i = 0; i < diff.size(); i++){
            int curr = diff[i];
            curr -= (tmr*2);
            if(curr <= 0) break;
            safe += (curr - 1);
            if(curr == 1) safe++;
            tmr += 2;
        }
        cout << n - safe << endl;
    }
    return 0;
}
