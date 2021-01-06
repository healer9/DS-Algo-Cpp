//practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#
#include <bits/stdc++.h>
using namespace std;

vector<int> pieTable(string pattern)
{
    int n = pattern.size();
    vector<int> reset(n);
    reset[0] = 0;
    int i = 1, len = 0;
    while (pattern[i] != '\0')
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            reset[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = reset[len - 1];
            }
            else
            {
                reset[i] = 0;
                i++;
            }
        }
    }
    return reset;
}

bool KMP(string mainStr, string pattern)
{
    // get the LPS table or pie table
    vector<int> lps = pieTable(pattern);
    int N = mainStr.size();
    int M = lps.size();

    int i = 0; // index for mainStr[]
    int j = 0; // index for pattern[]
    bool found = false;
    while (i < N)
    {
        if (pattern[j] == mainStr[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
            found = true;
        }

        // mismatch after j matches
        else if (i < N && pattern[j] != mainStr[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return found;
}

int main(int argc, char *argv[])
{
    string mainStr, pattern;
    cin >> mainStr >> pattern;

    // vector<int> pieMap = pieTable(pattern);
    // for (int i : pieMap)
    //     cout << i << " ";

    if (!KMP(mainStr, pattern))
        cout << "Pattern Not Found";

    cout << endl;

    return 0;
}