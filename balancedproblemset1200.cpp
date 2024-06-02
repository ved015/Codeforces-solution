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
            for(int i = dividend-1; i>= 1; i--){
                if((x - (n*i))%i == 0){
                    cout << i << endl;
                    break;
                }
            }
        }            
    }
    return 0;
}