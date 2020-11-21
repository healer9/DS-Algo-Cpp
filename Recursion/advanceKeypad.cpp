//hack.codingblocks.com/app/contests/1211/1092/problem
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string searchIn[] = {
    "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"};

string table[] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> strPer;

void keyPermutation(string inp, char *out, int i, int j)
{
    if (inp[i] == '\0')
    {
        out[j] = '\0';
        strPer.push_back(out);
        return;
    }

    int digit = inp[i] - '0';
    for (int k = 0; table[digit][k] != '\0'; k++)
    {
        out[j] = table[digit][k];
        keyPermutation(inp, out, i + 1, j + 1);
    }
}

int main()
{
    string inp;
    cin >> inp;

    char out[100];

    keyPermutation(inp, out, 0, 0);

    vector<string> ans;

    for (string s : strPer)
    {
        for (string str : searchIn)
        {
            size_t found = str.find(s);

            if (found != string::npos)
            {
                ans.push_back(str);
                break;
            }
        }
    }

    for (string s : ans)
        cout << s << endl;

    return 0;
}