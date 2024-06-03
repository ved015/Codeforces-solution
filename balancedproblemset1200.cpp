#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int x,n;
        cin >> x >> n;
        
        int dividend = x/n;
        int remainder = x%n;

        if(remainder == 0 || remainder%dividend == 0){
            cout << dividend << endl;
        }
        else{
            int ans = 0;
            for(int i = 1; i*i <= x; i++){
                if(x%i ==0){
                    int N = x/i;
                    if(N >= n){
                        ans = max(ans, i);
                    }
                    int j = x/i;
                    N = x/j;
                    if(N >= n){
                        ans = max(ans, j);
                    }
                }
            }
            cout << ans << endl;
        }            
    }
    return 0;
}