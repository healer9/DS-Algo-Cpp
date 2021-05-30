// leetcode.com/problems/subsets/
#include <iostream>
#include <string>
using namespace std;
//Input = {a , b, c}
// Output
//                 abc
// {}              000
// {c}             001
// {b}             010
// {b, c}          011
// {a}             100
// {a, c}          101
// {a, b}          110
// {a, b, c}       111

bool bitIsSet(int num, int pos)
{
    int mask = 1 << pos;
    return (num & mask) != 0;
}

void allPossibleSubsets(string &s, int n)
{
    // we have total 2^n permutations
    for (int i = 0; i < (1 << n); i++)
    {
        cout << "{ ";
        for (int j = 0; j < n; j++)
        {
            if (bitIsSet(i, j))
            {
                cout << s[j] << ", ";
            }
        }
        cout << "}" << endl;
    }
}

int main(int argc, char *argv[])
{
    string s;
    cin >> s;
    allPossibleSubsets(s, s.size());
    return 0;
}