#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> x(n),y(n);
        for(long long i = 0; i < n; i++){
            cin >> x[i];
        }
        for(long long i = 0; i < n; i++){
            cin >> y[i];
        }

        vector<long long> diff;
        for(long long i = 0; i < n; i++){
            diff.push_back(y[i] - x[i]);
        }
        sort(diff.begin(),diff.end());

        long long i = 0, j = diff.size()-1;
        long long count = 0;
        while(i < j){
            if(diff[i] + diff[j] >= 0){
                i++;
                j--;
                count++;
            }
            else i++;
        }

        cout << count << endl;
    }
    return 0;
}