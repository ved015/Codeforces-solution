#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> nums(n);
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }

    bool fullReplace = false;
    int replaceVal = 0;
    vector<long long> result;

    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int index, x;
            cin >> index >> x;
            --index;

            if (fullReplace) {
                sum = sum - replaceVal + x;
                nums[index] = x;
            } else {
                sum = sum - nums[index] + x;
                nums[index] = x;
            }

            cout << sum << endl;
        } else if (t == 2) {
            int y;
            cin >> y;

            replaceVal = y;
            fullReplace = true;
            sum = (long long)n * y;

            cout << sum << endl;
        }
    }

    return 0;
}
