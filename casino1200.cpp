#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,m;
        cin >> n >> m;
        vector<vector<long long> > grid(n,vector<long long>(m,0));
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < m; j++){
                long long a;
                cin >> a;
                grid[i][j] = a;
            }
        }

        long long ans = 0;
        for(long long k = 0; k < m; k++){
            vector<long long> column;
            for(long long j = 0; j < n; j++){
                column.push_back(grid[j][k]);
            }
            sort(column.begin(),column.end());

            long long prefixsum = 0;
            long long totsum = 0;
            for(auto &it : column){
                totsum += it;
            }
            for(long long i = 0; i < n; i++){
                ans += totsum - ((n - i)*column[i]) - prefixsum;
                prefixsum += column[i];
            }
        }
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        cout << ans << endl;

    }
    return 0;
}