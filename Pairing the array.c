#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int k;
    cin >> k;

    int n;
    cin >> n;

    vector<long long> freq(k + 1, 0);

    long long answer = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        int g = gcd((long long)x, (long long)k);

        // Check with all previously seen GCD values
        for (int j = 1; j <= k; j++) {
            if (freq[j] > 0 && ((long long)g * j) % k == 0) {
                answer += freq[j];
            }
        }

        freq[g]++;
    }

    cout << answer << endl;

    return 0;
}