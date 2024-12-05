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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool flag = true;
        int zero = 0,one = 0,question = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            if(s[r] == '0') zero++;
            else if(s[r] == '1') one++;
            else question++;

            if(r - l + 1 == k){
                int diff = abs(one - zero);
                if(question < diff || (question - diff)%2 != 0) flag = false;
                if(s[l] == '1') one--;
                else if(s[l] == '0') zero--;
                else question--;
                l++;
            }
        }
        if(flag == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}