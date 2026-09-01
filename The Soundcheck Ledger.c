#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int n;
    long long L;

    cin >> n >> L;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    deque<int> maxDeque;
    deque<int> minDeque;

    int left = 0;
    int answer = 0;

    for (int right = 0; right < n; right++) {

        // Maintain decreasing deque for maximum
        while (!maxDeque.empty() && a[maxDeque.back()] <= a[right]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(right);

        // Maintain increasing deque for minimum
        while (!minDeque.empty() && a[minDeque.back()] >= a[right]) {
            minDeque.pop_back();
        }
        minDeque.push_back(right);

        // Shrink window if difference is greater than L
        while (a[maxDeque.front()] - a[minDeque.front()] > L) {

            if (maxDeque.front() == left) {
                maxDeque.pop_front();
            }

            if (minDeque.front() == left) {
                minDeque.pop_front();
            }

            left++;
        }

        // Current window length
        int length = right - left + 1;

        if (length > answer) {
            answer = length;
        }
    }

    cout << answer << endl;

    return 0;
}