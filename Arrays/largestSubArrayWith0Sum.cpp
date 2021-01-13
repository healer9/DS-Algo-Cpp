//practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
#include <bits/stdc++.h>
using namespace std;

int largestSum(vector<int> &a, const int &targetSum)
{
    unordered_map<int, int> prevSumTrack;
    int currentSum = 0;
    int maxLength = 0;
    for (int i = 0; i < a.size(); i++)
    {
        currentSum += a[i];

        if (a[i] == 0 && maxLength == 0)
            maxLength = 1;

        if (currentSum == targetSum)
            maxLength = i + 1;

        if (prevSumTrack.find(currentSum - targetSum) != prevSumTrack.end())
            maxLength = max(maxLength, i - prevSumTrack[currentSum - targetSum]);
        else
            prevSumTrack[currentSum] = i;
    }

    return maxLength;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    const int targetSum = 0;
    cout << largestSum(a, targetSum) << endl;

    return 0;
}