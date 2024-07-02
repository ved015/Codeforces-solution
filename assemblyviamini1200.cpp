#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long b_size = (n*(n-1))/2;

        vector<int> b(b_size);

        for(int i = 0; i < b_size; i++){
            int a;
            cin >> a;
            b[i] = a;
        } 
        sort(b.begin(),b.end());
        vector<int> arr_a(n,-1);

        int i = 0,j = 0,k = 1;
        while(i < n && j < b_size){
            arr_a[i] = b[j];
            j += n - k;
            i++;
            k++;
        }
        arr_a[n-1] = arr_a[n-2];

        for(auto it : arr_a){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}