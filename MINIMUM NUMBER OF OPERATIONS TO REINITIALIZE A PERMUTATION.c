#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int current = 1;
    int operations = 0;

    do {
        // Find where the element at position 'current'
        // moves after one operation.

        if (current < n / 2) {
            current = current * 2;
        }
        else {
            current = (current - n / 2) * 2 + 1;
        }

        operations++;

    } while (current != 1);

    cout << operations << endl;

    return 0;
}