#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;
bool ispossible(int a,int b,int plus,int minus){
    if(plus == minus) return true;
    int min_symbol = min(plus,minus);
    int max_symbol = max(plus,minus);
    int max_element = max(a,b);
    int min_element = min(a,b);
    int l = 0,r = min_symbol;
    while(l <= r){
        int mid = l + (r - l)/2;
        int sign = (min_symbol == plus) ? 1 : -1; 
        int notsign = -1*sign;
        ll val = ((ll)max_element*mid*sign) + ((ll)min_element*(min_symbol - mid)*sign) + ((ll)min_element*max_symbol*notsign);
        if(val == 0){
            return true;
        }
        if(val > 0){
            if(min_symbol == plus) r = mid - 1;
            else l = mid + 1;
        }
        if(val < 0){
            if(min_symbol == plus) l = mid + 1;
            else r = mid - 1;
        }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int plus = 0,minus = 0;
    for(auto it : s){
        if(it == '+') plus++;
        else minus++;
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        if(ispossible(a,b,plus,minus)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }   
    return 0;
}