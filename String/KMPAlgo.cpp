#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> pieTable(string pattern)
{
    vector<pair<char, int>> result;
    int found[26] = {0};
    for (int i = 0; i < pattern.size(); i++)
    {
        if (!found[pattern[i] - 'a'])
        {
            found[pattern[i] - 'a'] = i + 1;
            result.push_back({pattern[i], 0});
        }
        else if (found[pattern[i] - 'a'])
        {
            result.push_back({pattern[i], found[pattern[i] - 'a']});
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    string mainStr, pattern;
    cin >> mainStr >> pattern;

    vector<pair<char, int>> pieMap = pieTable(pattern);
    for (auto temp : pieMap)
        cout << temp.first << "->" << temp.second << endl;

    return 0;
}