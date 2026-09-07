#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int to;
    long long weight;
};

struct State {
    long long distance;
    int node;
    int used;

    bool operator>(const State& other) const {
        return distance > other.distance;
    }
};

int main() {
    int n, m, k, src, dst;
    cin >> n >> m >> k >> src >> dst;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;

        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    // dist[node][used] = minimum cost to reach node
    // after using 'used' tokens
    vector<vector<long long>> dist(
        n + 1,
        vector<long long>(k + 1, LLONG_MAX)
    );

    priority_queue<State, vector<State>, greater<State>> pq;

    dist[src][0] = 0;
    pq.push({0, src, 0});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        long long d = current.distance;
        int u = current.node;
        int used = current.used;

        // Ignore outdated states
        if (d != dist[u][used]) {
            continue;
        }

        for (Edge edge : graph[u]) {
            int v = edge.to;
            long long w = edge.weight;

            // Option 1: Don't use a token
            if (dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }

            // Option 2: Use one token
            if (used < k) {
                if (dist[v][used + 1] > d) {
                    dist[v][used + 1] = d;
                    pq.push({dist[v][used + 1], v, used + 1});
                }
            }
        }
    }

    // We can use anywhere from 0 to k tokens
    long long answer = LLONG_MAX;

    for (int used = 0; used <= k; used++) {
        answer = min(answer, dist[dst][used]);
    }

    if (answer == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << answer << endl;
    }

    return 0;
}