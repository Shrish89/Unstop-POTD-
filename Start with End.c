#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];

    // Input elements
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int maxSum = arr[0] + arr[N - 1];

    // Find maximum symmetric pair sum
    for (int i = 0; i < N / 2; i++) {
        int sum = arr[i] + arr[N - 1 - i];

        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    cout << maxSum << endl;

    return 0;
}