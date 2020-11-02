// Take as input str, a string. The string contains a single pair of parenthesis “(..)”.
// Write a recursive function which returns the contents between the parenthesis.
// E.g. for “xyz(abc)def” return “abc”. Print the value returned.

// Sample Input
// abc(x)
// Sample Output
// x

#include <iostream>
#include <string>
using namespace std;

bool para = false;

void print(string s, string &ans, int i, int len)
{
    if (i == len || s[i] == ')')
    {
        para = false;
        return;
    }

    if (para)
    {
        ans += s[i];
        print(s, ans, i + 1, len);
    }

    if (s[i] == '(')
        para = true;

    print(s, ans, i + 1, len);
}

int main()
{
    string s, ans;
    cin >> s;

    print(s, ans, 0, s.size() - 1);

    cout << ans;
    return 0;
}