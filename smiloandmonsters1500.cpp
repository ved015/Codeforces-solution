#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    ll sum = 0;
    vector<ll> arr(n);
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr.begin(),arr.end());
    ll ans = 0;
    if(sum%2 == 1){ 
        ans=1; arr[0]--;
    }
    
    ll k = sum/2;
    
    
    ll c = 0;
    ll i = 0;
    while(i < n && c + arr[i] <= k){
        c += arr[i];
        i++;
    }
    
    ans = ans + k + (n-i);
    cout<<ans<<"\n";
   
}


int main(){
    ll t;
    cin >> t;
    
    while(t--)
    solve();
    
    return 0;
}