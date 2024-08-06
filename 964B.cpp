#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        int wins = 0;
        
        int sc[] = {a, b};
        int ssc[] = {c, d};
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        if (i != j && k != l) {
                            int sw = 0;
                            int ssw = 0;
                            
                            if (sc[i] > ssc[k]) sw++;
                            else if (sc[i] < ssc[k]) ssw++;
                            
                            if (sc[j] > ssc[l]) sw++;
                            else if (sc[j] < ssc[l]) ssw++;
                            
                            if (sw > ssw) wins++;
                        }
                    }
                }
            }
        }
        
        cout << wins << endl;
    }
    return 0;
}