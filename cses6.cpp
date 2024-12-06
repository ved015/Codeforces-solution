#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void NumberSpiral(ll Y, ll X)
{

    if (Y > X) {
        ll ans = (Y - 1) * (Y - 1);
        ll add = 0;

        if (Y % 2 != 0) {
            add = X;
        }
        else {
            add = 2 * Y - X;
        }
        cout << ans + add << "\n";
    }

    else {

        ll ans = (X - 1) * (X - 1);
        ll add = 0;

        if (X % 2 == 0) {
            add = Y;
        }
        else {
            add = 2 * X - Y;
        }
        cout << ans + add << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int Y,X;
        cin >> Y >> X;
        NumberSpiral(Y, X);
    }
}