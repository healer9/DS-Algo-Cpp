#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &a, int key)
{
    int start = 0, end = a.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == key)
            return mid + 1;
        else if (a[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int elementToSearch;
    cin >> elementToSearch;

    if (binarySearch(a, elementToSearch))
    {
        cout << "Element found at positon : " << binarySearch(a, elementToSearch) << endl;
    }
    else
    {
        cout << "Element not found\n";
    }

    return 0;
}