#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    int x = 0;

    // Calculate XOR of all elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        x = x ^ arr[i];
    }

    // If initial XOR is 0, Alice wins
    if (x == 0) {
        cout << "ALICE" << endl;
        return 0;
    }

    // Check if Alice can remove an element
    // such that the remaining XOR becomes 0.
    for (int i = 0; i < n; i++) {
        if ((x ^ arr[i]) == 0) {
            cout << "BOB" << endl;
            return 0;
        }
    }

    // Otherwise Alice wins
    cout << "ALICE" << endl;

    return 0;
}