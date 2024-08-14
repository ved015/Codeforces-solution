#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ones,zero;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') ones.push_back(i + 1);
        else zero.push_back(i + 1);
    }
    int count = 1;
    if(s[0] == '1'){
        while(true){
            int i = 0,j = 0;
            while(i < ones.size() && j < zero.size()){
                while(ones[i] < 0) i++;
                ones[i] = -1*count;
                while(zero[j] < ones[i] || zero[j] < 0){
                    j++;
                }
                zero[j] = -1*count;
            }
            count++;
            if(i == )
        }
    }
    else{

    }
    return 0;
}