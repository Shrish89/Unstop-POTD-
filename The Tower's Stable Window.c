#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int N;
    long long D;

    cin >> N >> D;

    long long a[100000];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    map<long long, int> freq;
    multiset<long long> values;

    int left = 0;
    int bestLength = 0;
    int bestStart = 0;

    for (int right = 0; right < N; right++) {
        freq[a[right]]++;
        values.insert(a[right]);

        // Remove elements until the window becomes valid
        while (freq[a[right]] > 1 ||
               (*values.rbegin() - *values.begin() > D)) {

            values.erase(values.find(a[left]));
            freq[a[left]]--;
            left++;
        }

        int currentLength = right - left + 1;

        // Update only if we find a longer window
        // This automatically keeps the earliest start in case of a tie
        if (currentLength > bestLength) {
            bestLength = currentLength;
            bestStart = left;
        }
    }

    cout << bestLength << " " << bestStart + 1 << endl;

    return 0;
}