//leetcode.com/problems/kth-largest-element-in-an-array/
#include <bits/stdc++.h>
using namespace std;

void randomization(vector<int> &a)
{
    const int size = a.size() - 1;
    srand(time(NULL));
    for (int i = size; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(a[i], a[j]);
    }
}

int partition(vector<int> &a, int start, int end)
{
    int pivot = a[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot) //reverse the comparision sign for kth largest element
        {                  //i.e, if(a[i] >= pivot)
            swap(a[pIndex], a[i]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[end]);
    return pIndex;
}

int kthSmallestElement(vector<int> &a, int start, int end, const int k)
{
    if (start > end)
        return -1;
    int pIndex = partition(a, start, end);
    if (pIndex == k)
        return a[k];
    if (pIndex > k)
        kthSmallestElement(a, start, pIndex - 1, k);
    else
        kthSmallestElement(a, pIndex + 1, end, k);
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int k;
    cin >> k;
    k--;

    randomization(a);

    cout << kthSmallestElement(a, 0, n - 1, k) << endl;
    a.clear();
    return 0;
}