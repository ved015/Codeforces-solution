#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t; 
    scanf("%d",&t);

    vector<int> dp(20000001, 0);
    vector<int> sum(20000001, 0);

    for (int i = 1; i <= 200000; ++i) {
        if(i < 10) {
            sum[i] = i;
        }
        else if(i%10 == 0){
            sum[i] = sum[i/10];
        }
        else{
            sum[i] = sum[i-1] + 1;
        }
        dp[i] = dp[i - 1] + sum[i];
    }

    while (t--) {
        int n; 
        scanf("%d", &n);
        
        cout << dp[n] << endl;
    }

    return 0;
}
