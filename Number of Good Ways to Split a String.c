#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    int left[100005];
    int right[100005];

    // Calculate distinct characters from left
    int count[26] = {0};
    int distinct = 0;

    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 0) {
            distinct++;
        }

        count[s[i] - 'a']++;
        left[i] = distinct;
    }

    // Reset count array
    for (int i = 0; i < 26; i++) {
        count[i] = 0;
    }

    distinct = 0;

    // Calculate distinct characters from right
    for (int i = n - 1; i >= 0; i--) {
        if (count[s[i] - 'a'] == 0) {
            distinct++;
        }

        count[s[i] - 'a']++;
        right[i] = distinct;
    }

    // Check every possible split
    int answer = 0;

    for (int i = 0; i < n - 1; i++) {
        if (left[i] == right[i + 1]) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}