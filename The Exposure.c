#include <bits/stdc++.h>
using namespace std;

/*
    Persistent Segment Tree:
    Used to answer:
        RANK l r k

    root[i] stores frequencies of exposure values
    from positions 1 to i.
*/

struct Node
{
    int left;
    int right;
    int count;

    Node(int l = 0, int r = 0, int c = 0)
        : left(l), right(r), count(c) {}
};

vector<Node> tree(1);   // node 0 = null node
vector<int> roots;


// Insert one compressed value into a new version
int update(int previous, int start, int end, int position)
{
    int current = tree.size();

    tree.push_back(tree[previous]);
    tree[current].count++;

    if (start == end)
        return current;

    int mid = start + (end - start) / 2;

    if (position <= mid)
    {
        tree[current].left =
            update(tree[previous].left, start, mid, position);
    }
    else
    {
        tree[current].right =
            update(tree[previous].right, mid + 1, end, position);
    }

    return current;
}


// Find kth smallest value in range l...r
int kthSmallest(int leftRoot,
                int rightRoot,
                int start,
                int end,
                int k)
{
    if (start == end)
        return start;

    int leftCount =
        tree[tree[rightRoot].left].count -
        tree[tree[leftRoot].left].count;

    int mid = start + (end - start) / 2;

    if (k <= leftCount)
    {
        return kthSmallest(
            tree[leftRoot].left,
            tree[rightRoot].left,
            start,
            mid,
            k
        );
    }

    return kthSmallest(
        tree[leftRoot].right,
        tree[rightRoot].right,
        mid + 1,
        end,
        k - leftCount
    );
}


/*
    Fenwick Tree / BIT:
    Used for:
        FLAG i
        AUDIT l r
*/

class FenwickTree
{
private:
    int n;
    vector<int> bit;

public:

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // Add value at position index
    void update(int index, int value)
    {
        while (index <= n)
        {
            bit[index] += value;
            index += index & (-index);
        }
    }

    // Prefix sum from 1...index
    int query(int index)
    {
        int sum = 0;

        while (index > 0)
        {
            sum += bit[index];
            index -= index & (-index);
        }

        return sum;
    }

    // Range sum l...r
    int rangeQuery(int left, int right)
    {
        return query(right) - query(left - 1);
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> exposure(N + 1);
    vector<int> values;

    for (int i = 1; i <= N; i++)
    {
        cin >> exposure[i];
        values.push_back(exposure[i]);
    }


    // ------------------------------------------------
    // Coordinate compression
    // ------------------------------------------------

    sort(values.begin(), values.end());

    values.erase(
        unique(values.begin(), values.end()),
        values.end()
    );

    int M = values.size();


    // ------------------------------------------------
    // Build persistent segment tree
    // ------------------------------------------------

    roots.resize(N + 1);
    roots[0] = 0;

    // Maximum number of nodes is roughly N * log(N)
    tree.reserve(N * 20 + 5);

    for (int i = 1; i <= N; i++)
    {
        int compressedPosition =
            lower_bound(
                values.begin(),
                values.end(),
                exposure[i]
            ) - values.begin();

        // Segment tree uses positions 1...M
        compressedPosition++;

        roots[i] = update(
            roots[i - 1],
            1,
            M,
            compressedPosition
        );
    }


    // ------------------------------------------------
    // Fenwick tree for FLAG/AUDIT
    // ------------------------------------------------

    FenwickTree fenwick(N);

    // flagged[i] = false initially
    vector<bool> flagged(N + 1, false);


    // ------------------------------------------------
    // Process Q events
    // ------------------------------------------------

    while (Q--)
    {
        string operation;
        cin >> operation;

        if (operation == "RANK")
        {
            int l, r, k;
            cin >> l >> r >> k;

            /*
                roots[r] contains positions 1...r
                roots[l-1] contains positions 1...l-1

                Their difference therefore represents l...r.
            */

            int compressedAnswer =
                kthSmallest(
                    roots[l - 1],
                    roots[r],
                    1,
                    M,
                    k
                );

            // Convert compressed position back
            // to original exposure value
            cout << values[compressedAnswer - 1] << '\n';
        }

        else if (operation == "FLAG")
        {
            int i;
            cin >> i;

            if (!flagged[i])
            {
                // Unflagged -> Flagged
                flagged[i] = true;
                fenwick.update(i, 1);
            }
            else
            {
                // Flagged -> Unflagged
                flagged[i] = false;
                fenwick.update(i, -1);
            }
        }

        else if (operation == "AUDIT")
        {
            int l, r;
            cin >> l >> r;

            cout << fenwick.rangeQuery(l, r) << '\n';
        }
    }

    return 0;
}