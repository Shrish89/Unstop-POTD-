#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Sort the coins
    sort(arr, arr + N);

    // Maximum possible difference
    int profit = arr[N - 1] - arr[0];

    cout << profit << endl;

    return 0;
}