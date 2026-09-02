#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int n = rowSum.size(), m = colSum.size();
    vector<vector<int>> matrix(n, vector<int>(m, 0)); // Initialize matrix with zeros

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Assign the minimum possible value
            matrix[i][j] = min(rowSum[i], colSum[j]);
            
            // Update row and column sums
            rowSum[i] -= matrix[i][j];
            colSum[j] -= matrix[i][j];
        }
    }
    return matrix;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> rowSum(n);
    vector<int> colSum(m);

    for (int i = 0; i < n; ++i) {
        cin >> rowSum[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> colSum[i];
    }

    vector<vector<int>> result = restoreMatrix(rowSum, colSum);

    for (const auto& row : result) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}