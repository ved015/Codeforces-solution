#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    ll total = ((ll)n*(n+1))/2;
    ll postivesegments = 0;
    map<int, int> count;
    count[0] = 1;

    int negative = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) {
            negative++;
        }
        if (negative % 2 == 0) {
            postivesegments += count[0];
        } else {
            postivesegments += count[1];
        }
        count[negative % 2]++;
    }
    cout << total - postivesegments << " " << postivesegments;
    return 0;
}