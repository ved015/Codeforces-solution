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
        vector <int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        sort(arr.begin(),arr.end());
        long long count = 0;
        for(int i = 0; i < n - 2; i++){
            for(int j = i+1; j < n - 1; j++){
                for(int k = j+1; k < n; k++){
                    if(arr[j] + 1 > arr[k]){
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}