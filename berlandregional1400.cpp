#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        map<ll, vector<ll> > teams;
        vector<ll> universities(n);
        
        for(int i = 0; i < n; i++){
            cin >> universities[i];
        }

        for(int i = 0; i < n; i++){
            ll a;
            cin >> a;
            teams[universities[i]].push_back(a);
        }
        
        map<ll, vector<ll> > prefix_sums;
        for(auto &it : teams){
            vector<ll> &temp = it.second;
            sort(temp.rbegin(), temp.rend());
            
            for(int i = 1; i < temp.size(); i++){
                temp[i] += temp[i - 1];
            }
            
            prefix_sums[it.first] = temp;
        }

        vector<ll> result(n + 1, 0);
        for(auto &it : prefix_sums){
            vector<ll> &prefix = it.second;
            ll size = prefix.size();
            
            for(int k = 1; k <= size; k++){
                result[k] += prefix[size - (size % k) - 1];
            }
        }

        for(int k = 1; k <= n; k++){
            cout << result[k] << " ";
        }
        cout << endl;
    }
    return 0;
}
