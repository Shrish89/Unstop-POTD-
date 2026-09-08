#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 2) {
        cout << 0;
        return 0;
    }

    vector<bool> isPrime(n, true);

    // 0 and 1 are not prime
    isPrime[0] = false;
    isPrime[1] = false;

    // Sieve of Eratosthenes
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;

    // Count primes strictly less than n
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    cout << count;

    return 0;
}