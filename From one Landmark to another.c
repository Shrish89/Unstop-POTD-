#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

vector<vector<int>> graph;
vector<long long> dp;

long long countPaths(int node, int n) {

    // Destination reached
    if (node == n) {
        return 1;
    }

    // Already calculated
    if (dp[node] != -1) {
        return dp[node];
    }

    long long ways = 0;

    for (int next : graph[node]) {
        ways = (ways + countPaths(next, n)) % MOD;
    }

    dp[node] = ways;

    return dp[node];
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    dp.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    cout << countPaths(1, n) << endl;

    return 0;
}