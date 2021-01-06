//hack.codingblocks.com/app/contests/1211/437/problem
//leetcode.com/problems/longest-common-subsequence/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void LCS(string s1, string s2)
{
    int l1 = s1.size() + 1;
    int l2 = s2.size() + 1;

    vector<vector<int>> dp(l1);
    for (int i = 0; i < l1; i++)
    {
        dp[i].resize(l2);
        if (i == 0)
        {
            for (int j = 0; j < l2; j++)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < l1; i++)
    {
        for (int j = 1; j < l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // for (int i = 0; i <= l1; i++)
    // {
    //     for (int j = 0; j <= l2; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << l1 << " " << l2 << endl;

    cout << "LCS lenght : " << dp[l1 - 1][l2 - 1] << endl;

    // to print real lcs
    int index = dp[l1 - 1][l2 - 1];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = s1.size(), j = s2.size();
    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    cout << lcs << endl;
}

int main(int argc, char *argv[])
{
    string s1, s2;
    cin >> s1 >> s2;

    LCS(s1, s2);

    return 0;
}