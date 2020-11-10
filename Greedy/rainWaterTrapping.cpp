//practice.geeksforgeeks.org/problems/trapping-rain-water/0
//leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> left(n), right(n);
        left[0] = arr[0];

        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], arr[i]);

        right[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], arr[i]);

        int amountTrapped = 0;

        for (int i = 0; i < n; i++)
            amountTrapped += min(left[i], right[i]) - arr[i];

        cout << amountTrapped << endl;
    }
    return 0;
}