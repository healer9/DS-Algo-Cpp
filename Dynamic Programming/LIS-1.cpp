#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &seq)
{
    const int n = (int)seq.size();
    vector<int> dp(n, 1);

    int lis = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (seq[i] > seq[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
                lis = max(lis, dp[i]);
            }
        }
    }

    return lis;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int &i : seq)
        cin >> i;

    cout << LIS(seq) << endl;
    return 0;
}