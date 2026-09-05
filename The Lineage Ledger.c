#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> depth(n + 1);
    vector<long long> dist(n + 1);

    // up[j][i] = 2^j-th ancestor of node i
    vector<vector<int>> up(LOG, vector<int>(n + 1));

    // DFS/BFS to calculate depth, distance and immediate parent
    queue<int> qu;
    vector<bool> visited(n + 1, false);

    qu.push(1);
    visited[1] = true;
    up[0][1] = 1;

    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (visited[v])
                continue;

            visited[v] = true;

            up[0][v] = u;
            depth[v] = depth[u] + 1;
            dist[v] = dist[u] + w;

            qu.push(v);
        }
    }

    // Binary lifting table
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }

    // Find LCA of two nodes
    auto LCA = [&](int a, int b) {
        if (depth[a] < depth[b])
            swap(a, b);

        // Bring a to the same depth as b
        int difference = depth[a] - depth[b];

        for (int j = 0; j < LOG; j++) {
            if (difference & (1 << j)) {
                a = up[j][a];
            }
        }

        if (a == b)
            return a;

        // Move both upwards
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][a] != up[j][b]) {
                a = up[j][a];
                b = up[j][b];
            }
        }

        return up[0][a];
    };

    int q;
    cin >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;

        int lca = LCA(x, y);

        // Total years between x and y
        long long years = dist[x] + dist[y] - 2 * dist[lca];

        // Number of rulers on the path, including both endpoints
        int rulers = depth[x] + depth[y] - 2 * depth[lca] + 1;

        cout << years << " " << rulers << '\n';
    }

    return 0;
}