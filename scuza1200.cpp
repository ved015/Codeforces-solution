#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

long long bs(long long leg,vector<pair<long long,long long> > &s){
    long long left = 0,right = s.size()-1;
    while(left <= right){
        long long mid = left + (right - left)/2;
        if(s[mid].first == leg){
            return s[mid].second;
        }
        else if(s[mid].first < leg){
            left = mid + 1;
        }
        else right = mid - 1;
    }
    if(right >= 0) return s[right].second;
    return -1;
}

int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n,q;
        cin >> n >> q;
        vector<long long> staircase(n),question(q);
        vector<long long> prefix(n);
        vector<pair<long long,long long> > s;
        long long sum = 0;

        for(long long i = 0; i < n; i++){
            cin >> staircase[i];
            prefix[i] = staircase[i] + sum;
            sum += staircase[i];
        }

        for(long long i = 0; i < q; i++){
            cin >> question[i];
        }

        long long maxi = staircase[0],index = 0;
        for(long long i = 1; i < n; i++){
           if(staircase[i] > maxi){
                s.push_back(make_pair(maxi,index));
                maxi = staircase[i];
                index = i;
           }
           else index++;
        }
        s.push_back(make_pair(maxi,index));

        vector<long long> ans;
        for(long long i = 0; i < q; i++){
            long long leg = question[i];
            long long index = bs(leg,s);
            if(index == -1) ans.push_back(0);
            else ans.push_back(prefix[index]);
        }

        for(auto &it : ans){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}