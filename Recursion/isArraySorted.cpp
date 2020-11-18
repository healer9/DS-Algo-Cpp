#include <iostream>
using namespace std;

bool isSorted(int *arr, int i, int n)
{
    if (i == n)
        return true;

    return arr[i + 1] > arr[i] ? isSorted(arr, i + 1, n) : false;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (isSorted(arr, 0, n - 1))
        cout << "Array is sorted\n";
    else
        cout << "Array is not sorted\n";

    return 0;
}