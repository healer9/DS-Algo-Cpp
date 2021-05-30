// https : //practice.geeksforgeeks.org/problems/heap-sort/1#
#include "iostream"
#include "vector"

// creating max-heap
void heapify(std::vector<int> &v, int idx, int size)
{
    int left = 2 * idx + 1;
    int right = left + 1;

    int max_idx = idx;
    int n = size - 1;

    if (left <= n and v[left] > v[max_idx])
        max_idx = left;
    if (right <= n and v[right] > v[max_idx])
        max_idx = right;

    if (max_idx != idx)
    {
        std::swap(v[idx], v[max_idx]);
        heapify(v, max_idx, n);
    }
}

// O(N)
void buildHeap(std::vector<int> &v)
{
    int n = (int)v.size() - 1 / 2;
    for (int i = n; i >= 0; --i)
        heapify(v, i, (int)v.size());
}

void heapSort(std::vector<int> &v)
{
    buildHeap(v);
    int n = (int)v.size() - 1;
    for (int i = n; i > 0; i--)
    {
        std::swap(v[0], v[i]);
        heapify(v, 0, i);
    }
}

int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;
    std::vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        v.push_back(val);
    }

    heapSort(v);

    for (int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}