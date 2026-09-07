#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    // rightMax[i] = maximum element from i to N-1
    vector<long long> rightMax(N);

    rightMax[N - 1] = nums[N - 1];

    for (int i = N - 2; i >= 0; i--) {
        rightMax[i] = max(nums[i], rightMax[i + 1]);
    }

    long long leftMin = nums[0];

    for (int j = 1; j < N - 1; j++) {

        // Check nums[i] < nums[j]
        // and nums[j] < nums[k]
        if (leftMin < nums[j] && nums[j] < rightMax[j + 1]) {
            cout << "YES";
            return 0;
        }

        leftMin = min(leftMin, nums[j]);
    }

    cout << "NO";

    return 0;
}