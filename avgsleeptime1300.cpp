#include <iostream>
#include <vector>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> sleep_times(n);
    for (int i = 0; i < n; ++i) {
        cin >> sleep_times[i];
    }

    long long sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += sleep_times[i];
    }

    long long total_sum = sum;

    for (int i = k; i < n; ++i) {
        sum += sleep_times[i] - sleep_times[i - k];
        total_sum += sum;
    }

    double average = static_cast<double>(total_sum) / (n - k + 1);

    cout << fixed << setprecision(6) << average << endl;

    return 0;
}
