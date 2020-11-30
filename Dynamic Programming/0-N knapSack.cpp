//hack.codingblocks.com/app/contests/1211/146/problem
// 0 -> leave the item (dp[i])
// 1 -> take the item (dp[i - weight[j]] + value[j])
// 0 - N (knapSack)
#include <iostream>
using namespace std;

int knapSack(int *val, int *weight, int n, int capacity)
{
    int dp[capacity + 1] = {0};

    for (int i = 0; i <= capacity; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= weight[j])
                dp[i] = max(dp[i], dp[i - weight[j]] + val[j]);
        }
    }

    // for (int i = 0; i <= capacity; i++)
    //     cout << dp[i] << " ";
    // cout << endl;

    return dp[capacity];
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