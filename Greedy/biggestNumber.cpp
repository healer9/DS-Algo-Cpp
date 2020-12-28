//hack.codingblocks.com/app/contests/1211/1086/problem
#include <bits/stdc++.h>
using namespace std;

string biggestNumber(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            string a = to_string(arr[i]) + to_string(arr[j]);
            string b = to_string(arr[j]) + to_string(arr[i]);
            if (a < b)
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    string num;
    for (int i = 0; i < arr.size(); i++)
        num += to_string(arr[i]);

    return num;
}

int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int &i : arr)
            cin >> i;
        cout << biggestNumber(arr) << endl;
    }

    return 0;
}