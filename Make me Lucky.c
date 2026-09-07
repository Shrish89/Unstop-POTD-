#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string S, U;
    cin >> S >> U;

    int n = S.length();
    int m = U.length();

    // Build LPS array for KMP
    vector<int> lps(m, 0);

    int len = 0;

    for (int i = 1; i < m; i++) {
        while (len > 0 && U[i] != U[len]) {
            len = lps[len - 1];
        }

        if (U[i] == U[len]) {
            len++;
        }

        lps[i] = len;
    }

    // Result string acts like a stack
    string result;

    // match[i] = number of characters of U matched
    // after adding result[i]
    vector<int> match(n);

    int j = 0;

    for (int i = 0; i < n; i++) {
        char c = S[i];

        // KMP matching
        while (j > 0 && c != U[j]) {
            j = lps[j - 1];
        }

        if (c == U[j]) {
            j++;
        }

        result.push_back(c);

        // Store current matching length
        match[result.size() - 1] = j;

        // If complete U is found
        if (j == m) {

            // Remove U from result
            for (int k = 0; k < m; k++) {
                result.pop_back();
            }

            // Restore matching state from the remaining result
            if (result.empty()) {
                j = 0;
            } else {
                j = match[result.size() - 1];
            }
        }
    }

    cout << result << endl;

    return 0;
}