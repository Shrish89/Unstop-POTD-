#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Line {
    ll m, c;

    ll value(ll x) {
        return m * x + c;
    }
};

// Check whether line b is unnecessary
bool bad(Line a, Line b, Line c) {
    // (c.c - a.c) / (a.m - c.m)
    // <=
    // (b.c - a.c) / (a.m - b.m)

    return (__int128)(b.c - a.c) * (a.m - c.m)
         >= (__int128)(c.c - a.c) * (a.m - b.m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll w;

    cin >> n >> w;

    vector<ll> energy(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> energy[i];
    }

    vector<ll> dp(n + 1);

    deque<Line> hull;

    // Night 1 must be active
    dp[1] = energy[1];

    // Line corresponding to j = 1
    hull.push_back({
        -2 * w * 1,
        dp[1] + w * 1LL * 1
    });

    for (int i = 2; i <= n; i++) {

        // Remove lines that will never give the minimum
        while (hull.size() >= 2 &&
               hull[0].value(i) >= hull[1].value(i)) {
            hull.pop_front();
        }

        ll best = hull.front().value(i);

        dp[i] = energy[i] + w * 1LL * i * i + best;

        // Add line for current night i
        Line newLine = {
            -2 * w * i,
            dp[i] + w * 1LL * i * i
        };

        while (hull.size() >= 2 &&
               bad(hull[hull.size() - 2],
                   hull[hull.size() - 1],
                   newLine)) {
            hull.pop_back();
        }

        hull.push_back(newLine);
    }

    cout << dp[n] << '\n';

    return 0;
}