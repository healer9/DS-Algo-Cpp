#include <bits/stdc++.h>
using namespace std;

void fAddress(string address, string mask)
{
}

vector<int> result(int n)
{
    vector<int> a(8, 0);
    int k = 7;
    while (n)
    {
        a[k--] = n & 1;
        n >>= 1;
    }
}

int main()
{
    string address;
    cout << "\nEnter the address : ";
    cin >> address;
    string mask;
    cout << "\nEnter the mask : ";
    cin >> mask;

    fAddress(address, mask);

    return 0;
}