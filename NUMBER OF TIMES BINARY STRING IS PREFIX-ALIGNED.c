#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> flips(N);

    for (int i = 0; i < N; i++) {
        cin >> flips[i];
    }

    int maxPosition = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        maxPosition = max(maxPosition, flips[i]);

        // After step i+1, positions 1 to i+1
        // must all be flipped.
        if (maxPosition == i + 1) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}