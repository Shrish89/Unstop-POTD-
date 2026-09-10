#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int K;
    cin >> K;

    // dp[i] = maximum sum for first i elements
    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++) {

        int maximum = 0;

        // Try all possible last partition sizes
        for (int j = 1; j <= K && j <= i; j++) {

            maximum = max(maximum, arr[i - j]);

            // j elements are replaced by their maximum
            dp[i] = max(dp[i], dp[i - j] + maximum * j);
        }
    }

    int M = dp[N];

    // Count primes from 2 to M
    int primeCount = 0;

    for (int num = 2; num <= M; num++) {

        bool isPrime = true;

        for (int j = 2; j * j <= num; j++) {
            if (num % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primeCount++;
        }
    }

    cout << primeCount << endl;

    return 0;
}