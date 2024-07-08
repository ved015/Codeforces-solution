#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> temp1, temp2;

        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            temp1.push_back(s);
        }

        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            temp2.push_back(s);
        }

        vector<vector<int> > grid1(n,vector<int>(m,0));
        vector<vector<int> > grid2(n,vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid1[i][j] = temp1[i][j] - '0';
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid2[i][j] = temp2[i][j] - '0';
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (grid1[i][j] != grid2[i][j]) {
                    if ((grid1[i][j] + 2) % 3 == grid2[i][j]) {
                        grid1[i][j] = grid2[i][j];
                        grid1[i + 1][j + 1] = (grid1[i + 1][j + 1] + 2) % 3;
                        grid1[i][j + 1] = (grid1[i][j + 1] + 1) % 3;
                        grid1[i + 1][j] = (grid1[i + 1][j] + 1) % 3;
                    } else {
                        grid1[i][j] = grid2[i][j];
                        grid1[i + 1][j + 1] = (grid1[i + 1][j + 1] + 1) % 3;
                        grid1[i][j + 1] = (grid1[i][j + 1] + 2) % 3;
                        grid1[i + 1][j] = (grid1[i + 1][j] + 2) % 3;
                    }
                }
            }
        }

        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (grid1[i][m - 1] != grid2[i][m - 1]) {
                ans = false;
                break;
            }
        }
        for (int j = 0; j < m; j++) {
            if (grid1[n - 1][j] != grid2[n - 1][j]) {
                ans = false;
                break;
            }
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
