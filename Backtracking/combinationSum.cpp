// https : // leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>
using namespace std;

void combinationSum(vector<int> &candidates, int i, int &n, int target, vector<vector<int>> &result, vector<int> temp)
{
    if (i == n or target < 0)
        return;

    if (target == 0)
    {
        result.push_back(temp);
        return;
    }

    temp.push_back(candidates[i]);
    combinationSum(candidates, i, n, target - candidates[i], result, temp);
    temp.pop_back();
    combinationSum(candidates, i + 1, n, target, result, temp);
}

int main()
{
    int n, target;
    cin >> n;
    vector<int> candidates(n);

    for (int &i : candidates)
    {
        cin >> i;
    }

    cin >> target;

    vector<vector<int>> result;
    vector<int> temp;
    combinationSum(candidates, 0, n, target, result, temp);

    for (auto r : result)
    {
        for (int i : r)
            cout << i << " ";
        cout << endl;
    }
}
