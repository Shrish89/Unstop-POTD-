#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    string target;
    cin >> target;

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // i and j must be different
            if (i != j) {
                if (nums[i] + nums[j] == target) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}