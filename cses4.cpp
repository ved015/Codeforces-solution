#include<iostream>
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll ans = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i-1] >= 0) continue;
            else{
                ans += abs(arr[i] - arr[i-1]);
                arr[i] = arr[i-1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}