#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,res = 2;
        cin>>n;
        vector < long long > v(n);
        for(long long i = 0 ; i < n ; i++) {
            cin>>v[i];
        }
        while(1) {
            set < long long > remainder;
            for(long long i = 0 ; i < (long long)v.size() ; i++) {
                remainder.insert(v[i]%res);
            }
            if((long long)remainder.size() == 2)
                break;
            res *= 2;
        }
        cout<<res<<endl;
    }
    return 0;
}