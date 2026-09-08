#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long moves = 0;

    for (long long i = 0; i < N; i++) {
        long long height = 2 * i + 1;

        if (height < N) {
            moves += N - height;
        }
    }

    cout << moves << endl;

    return 0;
}