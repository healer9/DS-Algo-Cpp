// In-bullt sorting function uses Randomised QuickSort
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void randomised(int *a, int end)
{
    srand(time(NULL));
    cout << time(NULL) << endl;
    for (int i = end; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(a[i], a[j]);
    }
}

int partition(int *a, int start, int end)
{
    int pivotElement = a[end];
    int pivotIndex = start;
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivotElement)
        {
            swap(a[i], a[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(a[pivotIndex], a[end]);
    return pivotIndex;
}

void quickSort(int *a, int start, int end)
{
    if (start >= end)
        return;
    int pivotIndex = partition(a, start, end);
    quickSort(a, start, pivotIndex - 1);
    quickSort(a, pivotIndex + 1, end);
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    randomised(a, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    delete[] a;
    return 0;
}