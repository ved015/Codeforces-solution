#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        string s;
        cin >> s;
        map<char,long long> m;
        long long maxfreq = -1;
        for(long long i = 0; i < n; i++){
            m[s[i]]++;
            maxfreq = max(maxfreq,m[s[i]]);
        }
        if(maxfreq > (n/2)){
            cout << (n - (n-maxfreq)*2) << endl;
        }
        else cout << n%2 << endl;
    }
    return 0;
}