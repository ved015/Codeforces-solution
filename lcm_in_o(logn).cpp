#include <iostream>
using namespace std;
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
    cout << lcm(15,20) << endl;
    return 0;
}
