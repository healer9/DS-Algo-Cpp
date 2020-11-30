// 0 -> leave the item (dp[i - 1][j])
// 1 -> take the item (dp[i-1][j - weight[i-1]] + value[i - 1])
// 0 - 1 (knapSack)
#include <iostream>
using namespace std;

int knapSack(int *val, int *weight, int n, int capacity)
{
    int dp[n + 1][capacity + 1];

    for (int j = 0; j < capacity + 1; j++)
        dp[0][j] = 0;

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (j >= weight[i - 1])
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - weight[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= capacity; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    return dp[n][capacity];
}

int main(int argc, char *argv[])
{
    int n, capacity;
    cin >> n >> capacity;

    int *val = new int[n];
    int *weight = new int[n];

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << knapSack(val, weight, n, capacity) << endl;
    delete[] weight;
    delete[] val;

    return 0;
}