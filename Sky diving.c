#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    // If there are no floors, no attempt is needed
    if (N == 0) {
        cout << 0;
        return 0;
    }

    // If there are no parachutes, we cannot perform any useful attempt
    if (K == 0) {
        cout << 0;
        return 0;
    }

    int dp[K + 1][N + 1];

    // 0 floors need 0 attempts
    for (int k = 1; k <= K; k++) {
        dp[k][0] = 0;
    }

    // 1 floor needs 1 attempt
    for (int k = 1; k <= K; k++) {
        dp[k][1] = 1;
    }

    // With 1 parachute, we have to check floors one by one
    for (int n = 0; n <= N; n++) {
        dp[1][n] = n;
    }

    // Fill the DP table
    for (int k = 2; k <= K; k++) {
        for (int n = 2; n <= N; n++) {

            dp[k][n] = n;  // Maximum possible attempts

            // Try dropping from every floor
            for (int x = 1; x <= n; x++) {

                int breaks = dp[k - 1][x - 1];
                int survives = dp[k][n - x];

                int attempts = 1 + max(breaks, survives);

                dp[k][n] = min(dp[k][n], attempts);
            }
        }
    }

    cout << dp[K][N];

    return 0;
}