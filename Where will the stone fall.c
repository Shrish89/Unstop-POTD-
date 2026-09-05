#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> answer(n);

    // Drop one stone from every column
    for (int start = 0; start < n; start++) {

        int col = start;
        bool stuck = false;

        // Move the stone through every row
        for (int row = 0; row < m; row++) {

            if (grid[row][col] == 1) {

                // Stone wants to move right
                if (col + 1 >= n || grid[row][col + 1] == -1) {
                    stuck = true;
                    break;
                }

                col++;
            }
            else {

                // Stone wants to move left
                if (col - 1 < 0 || grid[row][col - 1] == 1) {
                    stuck = true;
                    break;
                }

                col--;
            }
        }

        if (stuck)
            answer[start] = -1;
        else
            answer[start] = col;
    }

    // Print answer
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}