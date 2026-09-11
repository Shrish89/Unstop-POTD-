#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int child[2];

    TrieNode() {
        child[0] = -1;
        child[1] = -1;
    }
};

vector<TrieNode> trie;

void insertNumber(int x) {
    int node = 0;

    for (int bit = 30; bit >= 0; bit--) {
        int b = (x >> bit) & 1;

        if (trie[node].child[b] == -1) {
            trie[node].child[b] = trie.size();
            trie.push_back(TrieNode());
        }

        node = trie[node].child[b];
    }
}

int getMaximumXor(int x) {
    int node = 0;
    int result = 0;

    for (int bit = 30; bit >= 0; bit--) {
        int b = (x >> bit) & 1;
        int opposite = 1 - b;

        if (trie[node].child[opposite] != -1) {
            result |= (1 << bit);
            node = trie[node].child[opposite];
        } else {
            node = trie[node].child[b];
        }
    }

    return result;
}

int main() {
    int n, K;
    cin >> n >> K;

    vector<int> w(n + 1);
    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        prefix[i] = prefix[i - 1] ^ w[i];
    }

    int answer = 0;

    deque<int> window;

    for (int r = 1; r <= n; r++) {

        // Add P[r-1] to the window
        window.push_back(r - 1);

        // Remove prefix values that are too old
        while (!window.empty() && window.front() < r - K) {
            window.pop_front();
        }

        // Rebuild trie for the current valid prefix values
        trie.clear();
        trie.push_back(TrieNode());

        for (int index : window) {
            insertNumber(prefix[index]);
        }

        // Find maximum P[r] XOR P[l]
        answer = max(answer, getMaximumXor(prefix[r]));
    }

    cout << answer << endl;

    return 0;
}