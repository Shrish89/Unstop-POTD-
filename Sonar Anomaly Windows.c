#include <iostream>
#include <vector>
using namespace std;

const int MAX_BIT = 19;   // values are less than 2^20
const int MAX_NODES = 2100005;

struct Node {
    int child[2];
    int count;

    Node() {
        child[0] = 0;
        child[1] = 0;
        count = 0;
    }
};

Node trie[MAX_NODES];
int nodes = 0;

// Insert value into a new version of the trie
int insertValue(int oldRoot, int value) {
    int newRoot = ++nodes;

    trie[newRoot] = trie[oldRoot];
    trie[newRoot].count++;

    int oldNode = oldRoot;
    int newNode = newRoot;

    for (int bit = MAX_BIT; bit >= 0; bit--) {
        int b = (value >> bit) & 1;

        int oldChild = trie[oldNode].child[b];
        int newChild = ++nodes;

        trie[newChild] = trie[oldChild];
        trie[newChild].count++;

        trie[newNode].child[b] = newChild;

        oldNode = oldChild;
        newNode = newChild;
    }

    return newRoot;
}

// Find maximum (value XOR x) in range [l, r]
int query(int rootR, int rootL, int x) {
    int answer = 0;

    int nodeR = rootR;
    int nodeL = rootL;

    for (int bit = MAX_BIT; bit >= 0; bit--) {
        int xBit = (x >> bit) & 1;

        // To make XOR bit = 1, we want opposite bit
        int wanted = 1 - xBit;

        int rightChild = trie[nodeR].child[wanted];
        int leftChild = trie[nodeL].child[wanted];

        int available =
            trie[rightChild].count - trie[leftChild].count;

        if (available > 0) {
            // Opposite bit exists
            answer |= (1 << bit);

            nodeR = rightChild;
            nodeL = leftChild;
        }
        else {
            // Opposite bit doesn't exist, so take same bit
            nodeR = trie[nodeR].child[xBit];
            nodeL = trie[nodeL].child[xBit];
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    // root[i] = trie containing a[1...i]
    vector<int> root(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        root[i] = insertValue(root[i - 1], a[i]);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int l, r, x;
        cin >> l >> r >> x;

        cout << query(root[r], root[l - 1], x) << '\n';
    }

    return 0;
}