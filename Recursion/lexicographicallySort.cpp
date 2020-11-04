//hack.codingblocks.com/app/contests/1211/508/problem

#include <bits/stdc++.h>
using namespace std;

void lexicographically(int n, vector<string> &v)
{
    if (n == -1)
        return;

    v.push_back(to_string(n));
    lexicographically(n - 1, v);
}

int main()
{
    int n;
    cin >> n;

    vector<string> v;

    lexicographically(n, v);

    sort(v.begin(), v.end());

    for (string s : v)
        cout << s << " ";

    return 0;
}