#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int> > segments;
        for(int i = 0; i < n; i++){
            int l,r;
            cin >> l >> r;
            segments.push_back(make_pair(l,r));
        }
        
    }
    return 0;
}