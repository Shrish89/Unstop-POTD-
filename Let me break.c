#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;

    cin >> s1;
    cin >> s2;

    // If lengths are different
    if (s1.length() != s2.length()) {
        cout << "false" << endl;
        return 0;
    }

    // Sort both strings
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    bool s1Breaks = true;
    bool s2Breaks = true;

    // Check if s1 can break s2
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] < s2[i]) {
            s1Breaks = false;
            break;
        }
    }

    // Check if s2 can break s1
    for (int i = 0; i < s1.length(); i++) {
        if (s2[i] < s1[i]) {
            s2Breaks = false;
            break;
        }
    }

    if (s1Breaks || s2Breaks) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}