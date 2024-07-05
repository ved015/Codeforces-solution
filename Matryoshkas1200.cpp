#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> doll(n);
        map<int,int> m;
        for(int i = 0; i < n; i++){
            cin >> doll[i];
        }

        sort(doll.begin(),doll.end());
        for(auto it : doll){
            m[it]++;
        }

        int count = 0;
        while(true){
            auto it = m.begin();
            int first = it->first;
            while(m.find(first) != m.end() && m[first] != 0){
                m[first]--;
                if(m[first] == 0){
                    m.erase(first);
                }
                first++;
            }
            count++;
            if(m.size() == 0){
                break;
            }
        }

        cout << count << endl;
    }
    return 0;
}