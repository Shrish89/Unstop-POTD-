#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m;
    cin >> m;

    int q;
    cin >> q;

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    // Initial permutation
    vector<int> P;

    for (int i = 1; i <= m; i++) {
        P.push_back(i);
    }

    for (int i = 0; i < q; i++) {
        int x = queries[i];

        // Find position of x
        int pos = 0;

        while (P[pos] != x) {
            pos++;
        }

        // Print the position
        cout << pos << " ";

        // Move x to the beginning
        P.erase(P.begin() + pos);
        P.insert(P.begin(), x);
    }

    return 0;
}