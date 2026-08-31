#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int INF = 1e9; 
int max_path_len_limit;

// dp[u][0]: The length of the path segment starting at 'u' and extending downwards,
//           which needs to be connected to u's parent.
// dp[u][1]: The maximum length of any path that is fully contained (resolved) within the
//           subtree of 'u'.
// dp[u][2]: A temporary state used for merging logic.
int dp[200005][3];
vector<int> adj[200005];

void dfs(int u, int parent) {
    // Initialize DP states for the current node
    for (int i = 0; i < 3; ++i) {
        dp[u][i] = INF;
    }
    // A single node is a path of length 1 that can extend upwards
    dp[u][0] = 1;

    // Process all children first (post-order traversal)
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);

        // This loop iteratively merges the result from child 'v' into the state of 'u'.
        // It iterates backwards to use the state of 'u' *before* this child's merge.
        for (int i = 2; i >= 0; --i) {
            // If the current state for 'u' is already invalid, skip it.
            if (dp[u][i] == INF) continue;

            // --- Option 1: Merge the path from 'v' with a path from 'u' ---
            // 'i' represents the number of downward paths from 'u' we are considering.
            // A color-path can have at most degree 2, so we can't have more than 2 downward paths.
            if (i < 2) {
                // Check if merging the upward-path from v (dp[v][0]) with the i-th path from u (dp[u][i])
                // is valid. The merged path is now internal to u's subtree.
                // Merged length = len(path_u) + len(path_v) - 1 (since they meet at 'u')
                if (dp[u][i] + dp[v][0] - 1 <= max_path_len_limit) {
                    // This merge creates a state with i+1 downward paths. We update its cost.
                    // The new cost is the maximum length of the two paths being merged.
                    dp[u][i + 1] = min(dp[u][i + 1], max(dp[u][i], dp[v][0]));
                }
            }

            // --- Option 2: Treat the paths from 'v' as internal to 'u's new subtree ---
            // 'dp[v][1]' is the longest path fully contained within v's subtree.
            // We check if this path, when extended to u, is valid.
            // The total length of paths in u's subtree is now limited by the max of what we had
            // before (dp[u][i]) and this new internal path from v (dp[v][1] + 1).
            if (dp[u][i] + dp[v][1] > max_path_len_limit) {
                // If combining these makes a path too long, the current state `dp[u][i]` becomes invalid.
                dp[u][i] = INF;
            } else {
                // Otherwise, the cost of state `dp[u][i]` is the new maximum.
                dp[u][i] = max(dp[u][i], dp[v][1] + 1);
            }
        }
    }

    // After processing all children, finalize the DP states for 'u'.
    // The cost of having 0 paths going up is the minimum of having 0 or 1 path going up initially.
    dp[u][0] = min(dp[u][0], dp[u][1]);
    // The final cost for an entirely internal partition is the minimum of all calculated states.
    dp[u][1] = min(dp[u][0], dp[u][2]);
}

// Checks if the tree can be partitioned into paths of length at most 'k'.
bool check(int k) {
    max_path_len_limit = k;
    dfs(1, 0); // Run the DFS, starting from root 1 with no parent (0).
    // The check is successful if the longest internal path in the whole tree (dp[1][1])
    // is within the allowed limit.
    return dp[1][1] <= max_path_len_limit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int low = 1, high = n, ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}