#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n,w;
    cin>>n>>w;
    multiset<ll>ms;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        ms.insert(x);
    }
    int h=1,left=w;
    while(!ms.empty()){
        auto itr = ms.upper_bound(left);
        if(itr==ms.begin()){
            left=w;
            h++;
        }
        else{
            itr--;
            int val = *itr;
            left-=val;
            ms.erase(itr);
        }
    }
    cout<<h<<"\n";
}  
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
            int t=1;
            cin>>t;
            for(int i=1;i<=t;i++){
            //    cout<<"Case #"<<i<<": ";  
                solve();
    }
    return 0;
}