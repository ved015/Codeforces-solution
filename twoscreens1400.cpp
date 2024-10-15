#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s,t;
        cin >> s >> t;
        int s1 = s.size(),s2 = t.size();
        int cnt = 0;
        for(int i = 0; i < min(s1,s2); i++){
            if(s[i] == t[i]) cnt++;
            else break;
        }
        // add that one extra second for copying
        if(cnt > 0) cnt--;
        cout << s.size() + t.size() - cnt << endl;
    }
    return 0;
}