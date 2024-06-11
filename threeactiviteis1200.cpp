#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> arr1(n);
        vector <int> arr2(n);
        vector <int> arr3(n);
        for(int i = 0; i < n; i++) cin >> arr1[i];
        for(int i = 0; i < n; i++) cin >> arr2[i];
        for(int i = 0; i < n; i++) cin >> arr3[i];

        int sumi = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j) continue;
                    sumi = max(sumi,arr1[i] + arr2[j] + arr3[k]);
                }
            }
        }
        cout << sumi << endl;
    }
    return 0;
}