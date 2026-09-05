#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create prefix XOR array
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }

    int q;
    cin >> q;

    int columns;
    cin >> columns;  // Always 2

    for (int i = 0; i < q; i++) {
        int left, right;
        cin >> left >> right;

        long long answer = prefix[right + 1] ^ prefix[left];

        cout << answer;

        if (i != q - 1) {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}