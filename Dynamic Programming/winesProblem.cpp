#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &p, int i, int j, int year)
{
    // No bottle left
    if (i > j)
        return 0;

    int op1 = p[i] * year + maxProfit(p, i + 1, j, year + 1);
    int op2 = p[j] * year + maxProfit(p, i, j - 1, year + 1);

    return max(op1, op2);
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &i : p)
        cin >> i;

    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++)
        dp[i].resize(n);

    cout << maxProfit(p, 0, n - 1, 1) << endl;

    return 0;
}