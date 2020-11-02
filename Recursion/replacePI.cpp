// https: //hack.codingblocks.com/app/contests/1211/1381/problem

#include <iostream>
#include <string>
using namespace std;

void replacePie(string s, string &ans, int i, int len)
{
    if (i >= len)
        return;

    if (s[i] == 'p' and s[i + 1] == 'i')
    {
        ans += "3.14";
        replacePie(s, ans, i + 2, len);
    }
    else
    {
        ans += s[i];
        replacePie(s, ans, i + 1, len);
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s, ans;
        cin >> s;

        replacePie(s, ans, 0, s.size());

        cout << ans << endl;
    }
    return 0;
}