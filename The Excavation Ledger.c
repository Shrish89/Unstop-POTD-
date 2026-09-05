#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> count(k, 0);

    long long sum = 0;
    long long answer = 0;

    // Empty prefix has remainder 0
    count[0] = 1;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        sum += x;

        // Handle negative numbers
        long long rem = ((sum % k) + k) % k;

        // All previous prefix sums with same remainder
        // form a valid subarray with current prefix
        answer += count[rem];

        count[rem]++;
    }

    cout << answer << endl;

    return 0;
}