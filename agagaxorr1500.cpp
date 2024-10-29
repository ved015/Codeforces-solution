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
        ll n;
        cin >> n;
        vector<ll> nums(n);
        for(ll i = 0; i < n; i++){
            cin >> nums[i];
        }

        ll totalXor = 0;
        for(ll i = 0; i < n; i++){
            totalXor ^= nums[i];
        }
        // a1 a2 a3 a4 a5
        // XOR of 1^1 = 0
        // XOR of 1^0 = 1
        // x1 a3 a4 a5
        // xor of entire array will be less than equal to max(arr[i]);
        // 0010 -> a
        // 0011 -> b
        // 0001 -> c
        // 1010 -> d
        // a^b then c^d then (a^b)^(c^d)
        // a^b then (a^b)^c then ((a^b)^c)^d 
        // basically bcz adjacent are allowed so leaving 1st rem ka xor
        // or leaing last rem ka xor
        // or first x ka xor and remaininh n - x or
        // so for a b c d
        // a (b^c^d)
        // (a^b^c) d
        // a^b and c^d
        // so basically a then rem
        // a^b then rem
        // a^b^c then rem
        // so what we can do is store prefix and suffix xor and if they equal return true
        if(totalXor == 0){
            cout << "YES" << endl;
            continue;
        }

        ll prefixXor = 0, count = 0;
        for(ll i = 0; i < n; i++){
            prefixXor ^= nums[i];
            if(prefixXor == totalXor){
                count++;
                prefixXor = 0;
            }
        }

        if(count >= 2){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
