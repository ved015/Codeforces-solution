#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

 
int main(){
    vector<int>num = {4, 8, 15, 16, 23, 42};
    vector<int>ans(4);
    for(int i=1;i<=4;i++){
        cout<<"? "<<i<<" "<<i+1<<"\n";
        cin>>ans[i-1];
    }
    do{
        bool flag=true;
        for(int i=0;i<4;i++)
            flag=flag&(num[i]*num[i+1]==ans[i]);
        if(flag)
            break;
    }while(next_permutation(num.begin(),num.end()));
    cout<<"! ";
    for(auto i:num)
        cout<<i<<" ";
	return 0;
}