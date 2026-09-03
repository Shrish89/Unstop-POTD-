#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Store queen positions
    set<pair<int, int>> queens;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        queens.insert({x, y});
    }

    int kingX, kingY;
    cin >> kingX >> kingY;

    // 8 possible directions
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    vector<pair<int, int>> result;

    // Check all 8 directions
    for (int d = 0; d < 8; d++) {
        int x = kingX + dx[d];
        int y = kingY + dy[d];

        while (x >= 0 && x < 8 && y >= 0 && y < 8) {

            // First queen found in this direction attacks the king
            if (queens.count({x, y})) {
                result.push_back({x, y});
                break;
            }

            x += dx[d];
            y += dy[d];
        }
    }

    // Print result
    for (auto q : result) {
        cout << q.first << " " << q.second << " ";
    }

    return 0;
}