//leetcode.com/problems/unique-paths/
#include <iostream>
using namespace std;

int uniquePaths(int m, int n)
{
    int dp[1000][1000];

    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int j = 0; j < n; j++)
        dp[0][j] = 1;

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }

    return dp[m - 1][n - 1];
}

int main(int argc, char *argv[])
{
    int row, col;
    cin >> row >> col;

    cout << uniquePaths(row, col) << endl;
    return 0;
}