#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

void update(int node, int start, int end, int pos, int value)
{
    if (start == end)
    {
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;

    if (pos <= mid)
        update(2 * node, start, mid, pos, value);
    else
        update(2 * node + 1, mid + 1, end, pos, value);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r)
{
    if (r < start || end < l)
        return 0;

    if (l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;

    return query(2 * node, start, mid, l, r)
         + query(2 * node + 1, mid + 1, end, l, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int q;
    cin >> q;

    // Store queries
    vector<pair<pair<int, int>, int>> queries(q);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        queries[i] = {{l, r}, i};
    }

    // Sort queries by right endpoint
    sort(queries.begin(), queries.end(),
         [](auto &x, auto &y)
         {
             return x.first.second < y.first.second;
         });

    tree.resize(4 * n, 0);

    // Last occurrence of every artist
    unordered_map<long long, int> last;

    vector<int> answer(q);

    int currentRight = 0;

    for (auto queryData : queries)
    {
        int l = queryData.first.first;
        int r = queryData.first.second;
        int index = queryData.second;

        // Process paintings until we reach r
        while (currentRight < r)
        {
            currentRight++;

            long long artist = a[currentRight];

            // If artist appeared before, remove its old occurrence
            if (last.find(artist) != last.end())
            {
                update(1, 1, n, last[artist], 0);
            }

            // Current occurrence becomes active
            update(1, 1, n, currentRight, 1);

            last[artist] = currentRight;
        }

        // Count active last occurrences in [l, r]
        answer[index] = query(1, 1, n, l, r);
    }

    for (int i = 0; i < q; i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}