#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> weight(N);
    vector<long long> dest(N);

    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> dest[i];
    }

    // Stores the index of wagons for which
    // we are still looking for a heavier wagon.
    vector<int> st;

    // Wait gap for every wagon
    vector<long long> gap(N, 0);

    // Find nearest strictly heavier wagon ahead
    for (int i = N - 1; i >= 0; i--) {

        while (!st.empty() && weight[st.back()] <= weight[i]) {
            st.pop_back();
        }

        if (!st.empty()) {
            gap[i] = st.back() - i;
        } else {
            gap[i] = 0;
        }

        st.push_back(i);
    }

    // Store total gap for each destination
    unordered_map<long long, long long> total;

    // Store destinations in first appearance order
    vector<long long> order;

    for (int i = 0; i < N; i++) {
        if (total.find(dest[i]) == total.end()) {
            total[dest[i]] = 0;
            order.push_back(dest[i]);
        }

        total[dest[i]] += gap[i];
    }

    // Print in first appearance order
    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << " " << total[order[i]] << endl;
    }

    return 0;
}