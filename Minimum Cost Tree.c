#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> st;
    st.push_back(1000000000); // large value as a sentinel

    int ans = 0;

    for (int i = 0; i < N; i++) {

        while (st.back() <= arr[i]) {
            int x = st.back();
            st.pop_back();

            ans += x * min(st.back(), arr[i]);
        }

        st.push_back(arr[i]);
    }

    // Remove remaining elements from the stack
    while (st.size() > 2) {
        int x = st.back();
        st.pop_back();

        ans += x * st.back();
    }

    cout << ans << endl;

    return 0;
}