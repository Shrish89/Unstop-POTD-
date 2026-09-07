#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n);
    vector<int> arr2(m);

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    int answer = 0;

    // arr[i] <= 100000, so we need at most 17 bits
    for (int bit = 0; bit < 17; bit++) {

        int count1 = 0;
        int count2 = 0;

        // Count elements having this bit set in arr1
        for (int i = 0; i < n; i++) {
            if (arr1[i] & (1 << bit)) {
                count1++;
            }
        }

        // Count elements having this bit set in arr2
        for (int i = 0; i < m; i++) {
            if (arr2[i] & (1 << bit)) {
                count2++;
            }
        }

        // Bit appears in XOR if number of occurrences is odd
        if (count1 % 2 == 1 && count2 % 2 == 1) {
            answer = answer | (1 << bit);
        }
    }

    cout << answer << endl;

    return 0;
}