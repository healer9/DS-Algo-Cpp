//hack.codingblocks.com/app/contests/1211/428/problem
#include <bits/stdc++.h>
using namespace std;

int minChange(int *coins, int &size, int change)
{
    vector<int> dp(change + 1, 0);

    dp[0] = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = coins[i]; j <= change; j++)
            dp[j] += dp[j - coins[i]];
    }

    return dp[change];
}

int main()
{
    int n, size;
    cin >> n >> size;

    int *coins = new int[size];

    for (int i = 0; i < size; i++)
        cin >> coins[i];

    cout << minChange(coins, size, n);
    delete[] coins;
    return 0;
}