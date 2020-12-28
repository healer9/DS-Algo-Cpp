//www.geeksforgeeks.org/largest-sum-contiguous-subarray/
#include <iostream>
#include <climits>
using namespace std;

void kadanesAlgo(int *a, int n)
{
    int maxSoFar = INT_MIN, maxEndigHere = 0;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        maxEndigHere += a[i];
        if (maxEndigHere < a[i])
        {
            start = i;
            maxEndigHere = a[i];
        }
        if (maxSoFar < maxEndigHere)
        {
            end = i;
            maxSoFar = maxEndigHere;
        }
    }
    cout << "Max contiguous sum = " << maxSoFar << endl;
    cout << "Sub array is : ";
    for (int i = start; i <= end; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    kadanesAlgo(a, n);
    return 0;
}