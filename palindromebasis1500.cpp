#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

bool ispalindrome(int num){
    vector<int> digits;
    while(num > 0){
        digits.push_back(num % 10);
        num = num / 10;
    }
    int n = digits.size();
    int l = 0, r = n - 1;
    while(l <= r){
        if(digits[l] != digits[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}


int main(){
    int t;
    cin >> t;
    
    vector<ll> palindromes;
    for(int i = 1; i <= 40000; i++){
        if(ispalindrome(i)){
            palindromes.push_back(i);
        }
    }

    int size = palindromes.size();
    vector<vector<ll> > dp(size, vector<ll>(40001, 0));
    
    for (int i = 0; i < size; i++) {
        dp[i][0] = 1;
    }
    
    for (int idx = 0; idx < size; idx++) {
        for (int sum = 1; sum <= 40000; sum++) {
            ll nottake = (idx > 0) ? dp[idx - 1][sum] : 0;
            ll take = 0;
            
            if (sum >= palindromes[idx]) {
                take = dp[idx][sum - palindromes[idx]];
            }
            
            dp[idx][sum] = (take + nottake) % mod;
        }
    }

    while(t--){
        int n;
        cin >> n;
        
        cout << dp[size - 1][n] << endl;
    }
    
    return 0;
}
