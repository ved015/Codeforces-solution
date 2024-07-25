#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 1; i < n - 1; i++){
        if(s[i] == s[i-1]){
            for(char c = 'a'; c <= 'z'; c++){
                if(c != s[i] && c != s[i+1]){
                    s[i] = c;
                    break;
                }
            }
        }
    }
    // edge case
    if(s[n-1] == s[n-2]){
        for(char c = 'a'; c <= 'z'; c++){
            if(c != s[n-1]){
                s[n-1] = c;
                break;
            }
        }
    }
    for(auto it : s){
        cout << it;
    }
    return 0;
}