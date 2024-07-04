#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> permut(n);
        set <long long> s;
        for(long long i = 0; i < n; i++){
            cin >> permut[i];
            s.insert(permut[i]);
        }

        long long l = 0,r = n-1;

        while(r - l > 1){
            long long maxi = *s.rbegin(),mini = *s.begin();
            if(permut[l] != maxi && permut[l] != mini && permut[r] != maxi && permut[r] != mini){
                break;
            }
            if(permut[l] == maxi || permut[l] == mini){
                l++;
                s.erase(permut[l-1]);
            }
            if(permut[r] == maxi || permut[r] == mini){
                r--;
                s.erase(permut[r+1]);
            }

        }
        if(r - l > 1) cout << l + 1 << " " << r + 1 << endl;
        else cout << -1 << endl;
    }
    return 0;
}