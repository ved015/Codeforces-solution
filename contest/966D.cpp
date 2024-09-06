#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        long long sum = 0;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        cin >> s;

        int l = 0,r=n-1;
        long long ans = 0;
        while(l<r){
            while(s[l]=='R'){
                sum-=a[l];
                l++;
            } 
            while(s[r]=='L'){
                sum-=a[r];
                r--;
            }
            if(l>r) break;
            ans += sum;
            sum -= a[l];
            l++;
            sum-= a[r];
            r--;
        }
        cout<<ans<<endl;

    }

    return 0;
}
