#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

// Find the parent of a node
int findParent(int x, vector<int>& parent) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x], parent);
}

// Join two sets
void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);

    if (a == b)
        return;

    if (rank[a] < rank[b]) {
        parent[a] = b;
    }
    else if (rank[a] > rank[b]) {
        parent[b] = a;
    }
    else {
        parent[b] = a;
        rank[a]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by increasing cost
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    // Initially, every node is its own parent
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    long long totalCost = 0;
    int edgesUsed = 0;

    // Kruskal's Algorithm
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        long long w = edges[i].w;

        // If u and v are in different components
        if (findParent(u, parent) != findParent(v, parent)) {
            unite(u, v, parent, rank);

            totalCost += w;
            edgesUsed++;

            // MST has n-1 edges
            if (edgesUsed == n - 1)
                break;
        }
    }

    // If we couldn't connect all nodes
    if (edgesUsed != n - 1)
        cout << -1 << endl;
    else
        cout << totalCost << endl;

    return 0;
}