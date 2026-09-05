#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    for (int i = 0; i < N; i++) {
        long long shift;
        cin >> shift;

        // Reduce shift because there are only 26 letters
        shift = shift % 26;

        // Shift the character
        S[i] = 'a' + (S[i] - 'a' + shift) % 26;
    }

    cout << S << endl;

    return 0;
}