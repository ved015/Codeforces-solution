#include <iostream>
#include <cmath>
using namespace std;

int countFactor(long long x, int factor) {
    int count = 0;
    while (x % factor == 0) {
        x /= factor;
        count++;
    }
    return count;
}

long long customPow(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}
int degree(long long x,int b){
    long long val = x;
    int ans = 0;
    while(val > 1){
        ans++;
        val = val/b;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        long long product = n * m;
        int two = countFactor(n, 2);
        int five = countFactor(n, 5);
        int totalfive = degree(m, 5);
        int totaltwo = degree(m, 2);

        int increaseFive = min(two, totalfive);
        int increaseTwo = min(five, totaltwo);
        int tens = min(increaseFive, increaseTwo);

        long long powTen = customPow(10, tens);
        long long powTwo = customPow(2, increaseFive - tens);
        long long powFive = customPow(5, increaseTwo - tens);

        long long finalMultiplier = powTen * powTwo * powFive;

        if (finalMultiplier <= m) {
            cout << n * (m / finalMultiplier) * finalMultiplier << endl;
        } else {
            cout << n * m << endl;
        }
    }
    return 0;
}
