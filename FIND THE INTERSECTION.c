#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> firstList(N, vector<int>(2));

    for (int i = 0; i < N; i++) {
        cin >> firstList[i][0] >> firstList[i][1];
    }

    int M;
    cin >> M;

    vector<vector<int>> secondList(M, vector<int>(2));

    for (int i = 0; i < M; i++) {
        cin >> secondList[i][0] >> secondList[i][1];
    }

    int i = 0, j = 0;

    while (i < N && j < M) {

        // Find the intersection
        int start = max(firstList[i][0], secondList[j][0]);
        int end = min(firstList[i][1], secondList[j][1]);

        // If intersection exists
        if (start <= end) {
            cout << start << " " << end << " ";
        }

        // Move the interval which ends first
        if (firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }

    return 0;
}