#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool matches(string word, string pattern) {
    if (word.length() != pattern.length()) {
        return false;
    }

    int map1[26] = {0};
    int map2[26] = {0};

    for (int i = 0; i < word.length(); i++) {
        int a = word[i] - 'a';
        int b = pattern[i] - 'a';

        if (map1[a] == 0 && map2[b] == 0) {
            map1[a] = b + 1;
            map2[b] = a + 1;
        }
        else if (map1[a] != b + 1 || map2[b] != a + 1) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    vector<string> words(N);

    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    string pattern;
    cin >> pattern;

    vector<string> answer;

    for (int i = 0; i < N; i++) {
        if (matches(words[i], pattern)) {
            answer.push_back(words[i]);
        }
    }

    cout << answer.size() << endl;

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}