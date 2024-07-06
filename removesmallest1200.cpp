#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        string s;
        cin >> s;

        vector<bool> deleted(n + 1, false);
        long long ans = 0;

        for(long long k = 1; k <= n; k++){
            if(s[k - 1] == '0'){
                for(long long multiple = k; multiple <= n; multiple += k){
                    if(!deleted[multiple]){
                        if(s[multiple - 1] == '0'){
                            ans += k;
                            deleted[multiple] = true;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
