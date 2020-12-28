#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k = 0;
    cin >> n;
    vector<int> a(8, 0);

    while (n)
    {
        a[k++] = n & 1;
        n >>= 1;
    }

    for (int i = 7; i >= 0; i--)
        cout << a[i];
    cout << endl;
    return 0;
}