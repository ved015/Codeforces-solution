#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        vector<pair<int,int> > diff;
        for(int i = 0; i < n; i++){
            diff.push_back(make_pair(a[i]-b[i],i));
        }
        sort(diff.begin(),diff.end());
        int maxi = diff[diff.size()-1].first;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(diff[i].first == maxi){
                ans.push_back(diff[i].second + 1);
            }  
        }

        cout << ans.size() << endl;
        for(auto it : ans){
            cout << it << " ";  
        }
        cout << endl;
    }
    return 0;
}