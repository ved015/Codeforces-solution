#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

long long gcd(long long a, long long b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
long long lcm(long long a, long long b) 
{ 
    return (a / gcd(a, b)) * b; 
} 

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,x,y;
        cin >> n >> x >> y;
        ll ans = 0;

        ll commonmultiple = lcm(x,y);

        

        ll plusleft = (n/x) - (n/commonmultiple);

        ll minusleft = (n/y) - (n/commonmultiple);


        ans = (plusleft*n) - ((minusleft)*(minusleft+1))/2;
        
        plusleft--;
        ans -= ((plusleft)*(plusleft+1))/2;

        cout << ans << endl;
    }
    return 0;
}
