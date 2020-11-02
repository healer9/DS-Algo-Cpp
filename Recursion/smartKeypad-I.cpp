// https: //hack.codingblocks.com/app/contests/1211/742/problem

#include <iostream>
#include <string>
using namespace std;

string table[] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void possiblePermutaion(string s, char *out, int i, int j)
{
    if (s[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    int digit = s[i] - '0';

    for (int k = 0; table[digit][k] != '\0'; k++)
    {
        out[j] = table[digit][k];
        possiblePermutaion(s, out, i + 1, j + 1);
    }
}

int main()
{
    string s;
    cin >> s;
    char out[100];

    possiblePermutaion(s, out, 0, 0);

    return 0;
}