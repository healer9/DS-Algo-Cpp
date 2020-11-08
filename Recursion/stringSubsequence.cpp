//hack.codingblocks.com/app/contests/1211/153/problem

#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string input, string output, vector<string> &v)
{
    if (input.size() == 0)
    {
        v.push_back(output);
        return;
    }

    printSubsequences(input.substr(1), output, v);
    printSubsequences(input.substr(1), output + input[0], v);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string input, output;
        cin >> input;

        vector<string> v;
        printSubsequences(input, output, v);
        sort(v.begin(), v.end());

        for (string s : v)
            cout << s << endl;

        v.clear();
    }
    return 0;
}