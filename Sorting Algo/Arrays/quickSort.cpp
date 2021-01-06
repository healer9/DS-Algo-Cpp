#include <iostream>
using namespace std;

int partition(int *a, int s, int e)
{
    int i = s - 1;
    int j = s;
    int pivot = a[e];
    while (j < e)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
        j++;
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quickSort(int *a, int s, int e)
{
    if (s >= e)
        return;

    int pivot = partition(a, s, e);

    quickSort(a, s, pivot - 1);
    quickSort(a, pivot + 1, e);
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}