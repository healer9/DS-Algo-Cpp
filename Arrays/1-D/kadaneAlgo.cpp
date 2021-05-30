//www.geeksforgeeks.org/largest-sum-contiguous-subarray/
#include <iostream>
#include <climits>
using namespace std;

// smallestSumSubarr(arr, n)
//     Initialize min_ending_here = INT_MAX
//     Initialize min_so_far = INT_MAX

//     for i = 0 to n-1
//         if min_ending_here > 0
//             min_ending_here = arr[i]
//         else
//             min_ending_here += arr[i]
//         min_so_far = min(min_so_far, min_ending_here)

//     return min_so_far

void kadanesAlgo(int *a, int n)
{
    int maxEndingHere = 0, maxSoFar = INT_MIN;
    int s = 0, end = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        maxEndingHere += a[i];
        if (maxSoFar < maxEndingHere)
        {
            maxSoFar = maxEndingHere;
            start = s;
            end = i;
        }
        if (maxEndingHere < 0)
        {
            maxEndingHere = 0;
            s = i + 1;
        }
    }

    cout << "Max Sum = " << maxSoFar;
    // cout << start << " " << end << endl;
    cout << "\nSub array : ";
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