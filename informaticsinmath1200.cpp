#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
   int t;
   cin >> t;
   while(t--){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        set<int> s;
        for(int i = 1; i <=n; i++){
            int a;
            cin >> a;
            arr[i] = a;
            s.insert(a);
        }

        int mex = 0;
        for(auto it : s){
            if(it != mex){
                break;
            }
            mex++;
        }

        int count = 0;
        vector<pair<int, int> > ans;
        int l = 1;
        int i = 1;
        set<int> track;
        while(i<=n){
            if(arr[i] < mex){
                track.insert(arr[i]);
            }
            if(track.size() == mex){
                ans.push_back(make_pair(l,i));
                track.clear();
                l = i+1;
            }
            i++;
        }

        if(!ans.empty()){
            int endindex = ans[ans.size() - 1].second;
            if (endindex < n) {
                endindex++;
                while (endindex <= n) {
                    endindex++;
                }
                endindex--;
                ans[ans.size() - 1].second = endindex;
            }
        }

        int size = 0;
        for(auto it : ans){
            size += it.second - it.first + 1;
        }

        if(size == n && ans.size() >= 2){
            cout << ans.size() << endl;
            for(auto it : ans){
                cout << it.first << " " << it.second << endl;
            }
        }
        else cout << -1 << endl;
   }

    return 0;
}