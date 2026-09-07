#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<string>> orders(N);

    // Store each order according to its table
    for (int i = 0; i < M; i++) {
        int table;
        string item;

        cin >> table >> item;

        orders[table].push_back(item);
    }

    // Sort and print orders of every table
    for (int i = 0; i < N; i++) {

        sort(orders[i].begin(), orders[i].end());

        for (int j = 0; j < orders[i].size(); j++) {
            cout << orders[i][j];

            if (j != orders[i].size() - 1) {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}