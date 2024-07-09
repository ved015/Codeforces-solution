#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int counter(int i,int j,string &s,char ch){
    int count = 0;
    while(i <= j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else{
            if(s[i] == ch){
                i++;
                count++;
                continue;
            }
            else if(s[j] == ch){
                j--;
                count++;
                continue;
            }
            else{
                count = INT_MAX;
                break;
            }
        }
    }
    return count;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        char ch1 = '0',ch2 = '0';
        int i = 0,j = s.size()- 1;
        while(i <= j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                ch1 = s[i];
                ch2 = s[j];
                break;
            }
        }

        if(ch1 == '0' && ch2 ==  '0'){
            cout << 0 << endl;
        }
        else{
            int count1 = counter(0,s.size()-1,s,ch1);
            int count2 = counter(0,s.size()-1,s,ch2);

            if(count1 == INT_MAX && count2 == INT_MAX){
                cout << -1 << endl;
            }
            else cout << min(count1,count2) << endl;
        }
    }
    return 0;
}