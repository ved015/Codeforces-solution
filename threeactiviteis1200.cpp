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
        vector <pair<int,int> > arr1;
        vector <pair<int,int> > arr2;
        vector <pair<int,int> > arr3;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            arr1.push_back(make_pair(a,i));
        }
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            arr2.push_back(make_pair(a,i));
        }
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            arr3.push_back(make_pair(a,i));
        }

        sort(arr1.rbegin(), arr1.rend());
        sort(arr2.rbegin(), arr2.rend());
        sort(arr3.rbegin(), arr3.rend());

        int sumi = 0;

        for (int i = 0; i < min(n, 3); i++) {
            for (int j = 0; j < min(n, 3); j++) {
                if (arr2[j].second == arr1[i].second) continue;
                for (int k = 0; k < min(n, 3); k++) {
                    if (arr3[k].second == arr1[i].second || arr3[k].second == arr2[j].second ) continue;
                    sumi = max(sumi, arr1[i].first + arr2[j].first + arr3[k].first);
                }
            }
        }
        cout << sumi << endl;
    }
    return 0;
}