#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int child[36];
    bool end;

    Node() {
        end = false;

        for (int i = 0; i < 36; i++) {
            child[i] = -1;
        }
    }
};

int getIndex(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A';

    return ch - '0' + 26;
}

int main() {
    int N;
    cin >> N;

    vector<Node> trie(1);

    long long total = 0;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        int current = 0;
        int longestPrefix = 0;
        bool duplicate = true;

        // Find the longest registered prefix
        for (int j = 0; j < s.length(); j++) {
            int index = getIndex(s[j]);

            if (trie[current].child[index] == -1) {
                duplicate = false;
                break;
            }

            current = trie[current].child[index];

            // This registered string is a prefix of s
            if (trie[current].end) {
                longestPrefix = j + 1;
            }
        }

        // Check if the complete string already exists
        if (duplicate && trie[current].end) {
            cout << -1 << endl;
            continue;
        }

        int score = s.length() - longestPrefix;

        cout << score << endl;
        total += score;

        // Insert the new string into the Trie
        current = 0;

        for (int j = 0; j < s.length(); j++) {
            int index = getIndex(s[j]);

            if (trie[current].child[index] == -1) {
                trie[current].child[index] = trie.size();
                trie.push_back(Node());
            }

            current = trie[current].child[index];
        }

        trie[current].end = true;
    }

    cout << "Total: " << total << endl;

    return 0;
}