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
        vector<int> a(n),b(n),c(n);
        vector<pair<int,int> > ma,mb,mc;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            ma.push_back(make_pair(a[i],i));
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            mb.push_back(make_pair(b[i],i));
        }
        for(int i = 0; i < n; i++){
            cin >> c[i];
            mc.push_back(make_pair(c[i],i));
        }
        sort(ma.begin(),ma.end(),greater<pair<int,int> >());
        sort(mb.begin(),mb.end(),greater<pair<int,int> >());
        sort(mc.begin(),mc.end(),greater<pair<int,int> >());

        int ans = 0;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(ma[i].second != mb[j].second && (mc[k].second != mb[j].second && mc[k].second != ma[i].second)){
                        ans = max(ans,ma[i].first+mb[j].first+mc[k].first);
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}