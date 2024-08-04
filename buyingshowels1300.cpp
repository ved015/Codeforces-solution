#include<iostream>
#include<set>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(n <= k){
            cout << 1 << endl;
        }
        else{
            // highest divisor less than equal to k
            set<int> divisors;
            for(int i = 1; i <= sqrt(n); i++){
                if(n%i == 0){
                    if(i <= k) divisors.insert(i);
                    if(n/i <= k) divisors.insert(n/i);
                }
            }
            int val = *divisors.rbegin();
            cout << n/val << endl;
        }
    }
    return 0;
}

// int find_majority(int n, vector<int>& nums) {
//     int count = 0, el = -1;
//     for (int i = 0; i < n; i++) {
//         if (count == 0) {
//             el = nums[i];
//             count++;
//         } else if (nums[i] == el) {
//             count++;
//         } else {
//             count--;
//         }
//     }
//     count = 0;
//     for (int i = 0; i < n; i++) {
//         if (nums[i] == el) {
//             count++;
//         }
//     }
//     if (count > n / 2) return el;
//     return -1;
// }

