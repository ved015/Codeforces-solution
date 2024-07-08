#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,x;
        cin >> n >> x;
        vector<long long> shop(n);
        for(long long i = 0; i < n; i++){
            cin >> shop[i];
        }
        sort(shop.begin(),shop.end());
        vector<long long> prefix(n);
        long long sum = 0;
        for(long long i = 0; i < n; i++){
            prefix[i] = shop[i] + sum;
            sum += shop[i];
        }

        long long ans = 0;
        long long count  = 0;
        while(true){
            long long prevans = ans;
            long long s = 0,e = n-1;

            while(s <= e){
                long long mid = s + (e-s)/2;
                long long value = prefix[mid] + count*(mid+1);

                if(value > x && s == e){
                    ans += mid;
                    break;
                }

                if(value == x || (value < x && s == e)){
                    ans += mid + 1;
                    break;
                }

                if(value < x){
                    s = mid + 1;
                }
                else e = mid - 1;
            }
            count++;
            if(prevans == ans) break;
        }
        cout << ans << endl;
    }
    return 0;
}