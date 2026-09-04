#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int nums[100005];
    int freq[101] = {0};

    // Input and count frequency
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        freq[nums[i]]++;
    }

    // Convert frequency into prefix sum
    // freq[i] = number of elements <= i
    for (int i = 1; i <= 100; i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }

    // Find number of elements strictly smaller
    for (int i = 0; i < n; i++)
    {
        cout << freq[nums[i] - 1] << " ";
    }

    return 0;
}