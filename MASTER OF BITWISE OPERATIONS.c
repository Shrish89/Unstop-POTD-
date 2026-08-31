#include <bits/stdc++.h>
using namespace std;

vector<int> user_logic(int n, int q, vector<int>& arr, vector<array<int,5>>& queries) {
    // We need counts for bits 0 through 30 inclusive:
    static vector<vector<int>> prefix(31);
    // Prepare space
    for (int b = 0; b <= 30; ++b) {
        prefix[b].assign(n+1, 0);
    }
    // Build prefix sums: prefix[b][i] = # of arr[0..i-1] with bit b set
    for (int b = 0; b <= 30; ++b) {
        for (int i = 1; i <= n; ++i) {
            prefix[b][i] = prefix[b][i-1] + ((arr[i-1] >> b) & 1);
        }
    }
    
    vector<int> answers;
    answers.reserve(q);
    for (auto &qr : queries) {
        int k = qr[0];         // zero-based bit index in their description
        int X1 = qr[1], Y1 = qr[2];
        int X2 = qr[3], Y2 = qr[4];
        
        // Count ones in each range at bit k
        int o1 = prefix[k][Y1] - prefix[k][X1-1];
        int len1 = Y1 - X1 + 1;
        int z1 = len1 - o1;
        
        int o2 = prefix[k][Y2] - prefix[k][X2-1];
        int len2 = Y2 - X2 + 1;
        int z2 = len2 - o2;
        
        // XOR has bit k = 1 exactly when one side has 1 and the other 0
        long long res = (long long)o1 * z2 + (long long)z1 * o2;
        answers.push_back((int)res);
    }
    return answers;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        vector<array<int,5>> queries(Q);
        for (int i = 0; i < Q; ++i) {
            // read k, X1, Y1, X2, Y2
            // here k is exactly the zero-based bit index
            cin >> queries[i][0]
                >> queries[i][1]
                >> queries[i][2]
                >> queries[i][3]
                >> queries[i][4];
        }
        
        auto ans = user_logic(N, Q, A, queries);
        for (int x : ans) {
            cout << x << "\n";
        }
    }
    return 0;
}