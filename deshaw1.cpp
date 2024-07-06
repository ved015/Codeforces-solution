#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string num;
        cin >> num;
        string s;
        cin >> s;
        unordered_map<int,set<char> > m;
        
        m[2].insert('a');
        m[2].insert('b');
        m[2].insert('c');

        m[3].insert('d');
        m[3].insert('e');
        m[3].insert('f');

        m[4].insert('g');
        m[4].insert('h');
        m[4].insert('i');

        m[5].insert('j');
        m[5].insert('k');
        m[5].insert('l');

        m[6].insert('m');
        m[6].insert('n');
        m[6].insert('o');

        m[7].insert('p');
        m[7].insert('q');
        m[7].insert('r');
        m[7].insert('s');

        m[8].insert('t');
        m[8].insert('u');
        m[8].insert('v');

        m[9].insert('w');
        m[9].insert('x');
        m[9].insert('y');
        m[9].insert('z');
        
        int count = 0;
        bool flag = false;
        for (int i = 0; i < num.size(); i++) {
            auto it = m[num[i] - '0'];
            if (it.find(s[i]) == it.end()) {
                flag = true;
                break;
            }
        }

        if (!flag) count++;

        cout << count << endl;

    }
    return 0;
}