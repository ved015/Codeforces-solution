#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> a(n),b(n);
        for(int i = 1; i < n; i++){
            cin >> a[i];
        }
        a[0] = 1;
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i = 0,j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        cout << a.size() - i << endl;
    }
    return 0;
}