#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool arrtoint(int index, vector<int> &num1, vector<int> &num2){
    string a,b;
    for(int i = 0; i <= index; i++){
        a.push_back(num1[i] + '0');
        b.push_back(num2[i] + '0');
    }
    return a > b;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string n_str, m_str;
        cin >> n_str >> m_str;

        vector<int> num1, num2;
        for (char c : n_str) {
            num1.push_back(c - '0');
        }
        for (char c : m_str) {
            num2.push_back(c - '0');
        }
        int size = min(num1.size(),num2.size());
        
        // logic
        for(int i = 1; i < size; i++){
            int mini = min(num1[i],num2[i]);
            int maxi = max(num1[i],num2[i]);

            if(arrtoint(i-1, num1, num2)){
                num1[i] = mini;
                num2[i] = maxi;
            }
            else{
                num1[i] = maxi;
                num2[i] = mini;
            }
        }

        for(auto i : num1){
            cout << i;
        }

        cout << endl;

        for(auto i : num2){
            cout << i;
        }
        cout << endl;
    }
    return 0;
}