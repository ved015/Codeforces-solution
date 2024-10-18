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
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        string s;
        cin >> s;
        vector<int> prefix(n);
        prefix[0] = nums[0];
        int x1 = 0,x0 = 0;
        if(s[0] == '0') x0 = nums[0];
        else x1 = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1]^nums[i];
            if(s[i] == '0'){
                x0 = x0^nums[i];
            }
            else x1 = x1^nums[i];
        }
        int q;
        cin >> q;
        for(int i = 0; i < q; i++){
            int a;
            cin >> a;
            if(a == 1){
                int l,r;
                cin >> l >> r;
                x0 = x0^prefix[r-1];
                if(l > 1) x0 = x0^prefix[l-2];
                x1 = x1^prefix[r-1];
                if(l > 1) x1 = x1^prefix[l-2];
            }
            else{
                int g;
                cin >> g;
                if(g == 0) cout << x0 << " ";
                else cout << x1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}