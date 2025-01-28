#include <iostream>
#include <deque>
using namespace std;

void Josephus(int N, int k) {
    deque<int> people;
    deque<int> ans;

    for (int i = 1; i <= N; i++) {
        people.push_back(i);
    }

    int index = 0;


    while (!people.empty()) {

        index = (index + k - 1) % people.size();
        ans.push_back(people[index]);

        // Remove the person from the circle
        people.erase(people.begin() + index);
    }

    for (int it : ans) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    Josephus(n, 2);
    return 0;
}
