#include <iostream>
using namespace std;

void merge(int *arr, int *b, int *c, int start, int end)
{
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end)
    {
        if (b[i] < c[j])
        {
            arr[k++] = b[i++];
        }
        else
        {
            arr[k++] = c[j++];
        }
    }

    while (i <= mid)
    {
        arr[k++] = b[i++];
    }

    while (j <= end)
    {
        arr[k++] = c[j++];
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    int b[100], c[100];
    for (int i = start; i <= mid; i++)
        b[i] = arr[i];
    for (int i = mid + 1; i <= end; i++)
        c[i] = arr[i];

    mergeSort(b, start, mid);
    mergeSort(c, mid + 1, end);

    merge(arr, b, c, start, end);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}