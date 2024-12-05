#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

int main(){
    int t = 1;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int ans = 1,cnt = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]) cnt++;
            else cnt = 1;
            ans = max(ans,cnt);
        }
        cout << ans << endl;
    }
    return 0;
}