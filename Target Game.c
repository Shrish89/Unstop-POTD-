#include <iostream>
#include <vector>
using namespace std;

void findCombinations(vector<int>& arr, int n, int target,
                      int index, vector<int>& current)
{
    // Target reached
    if (target == 0)
    {
        for (int i = 0; i < current.size(); i++)
        {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }

    // Target becomes negative
    if (target < 0)
    {
        return;
    }

    // Try all numbers from current index
    for (int i = index; i < n; i++)
    {
        // Choose the current number
        current.push_back(arr[i]);

        // i is passed again because repetition is allowed
        findCombinations(arr, n, target - arr[i], i, current);

        // Remove the number and try another possibility
        current.pop_back();
    }
}

int main()
{
    int target;
    cin >> target;

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> current;

    findCombinations(arr, n, target, 0, current);

    return 0;
}