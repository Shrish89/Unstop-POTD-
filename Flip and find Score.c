#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Make the first bit of every row 1
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 0) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }

    // Make the number of 1s maximum in every column
    for (int j = 0; j < m; j++) {
        int ones = 0;

        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 1) {
                ones++;
            }
        }

        int zeros = n - ones;

        if (zeros > ones) {
            for (int i = 0; i < n; i++) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }

    // Calculate maximum score
    long long score = 0;

    for (int i = 0; i < n; i++) {
        long long number = 0;

        for (int j = 0; j < m; j++) {
            number = number * 2 + grid[i][j];
        }

        score += number;
    }

    // Sieve of Eratosthenes
    vector<bool> prime(score + 1, true);

    if (score >= 0)
        prime[0] = false;

    if (score >= 1)
        prime[1] = false;

    for (long long i = 2; i * i <= score; i++) {
        if (prime[i]) {
            for (long long j = i * i; j <= score; j += i) {
                prime[j] = false;
            }
        }
    }

    // Count primes <= score
    int count = 0;

    for (long long i = 2; i <= score; i++) {
        if (prime[i]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}