#include <iostream>
#include <vector>
using namespace std;

// O(N)


// O(NlogN)
void buildHeap(vector<int> &v, const int &size)
{
    for (int i = 2; i < size; i++)
    {
        int child = i;
        int parent = i / 2;
        while (child > 1 and v[child] > v[parent])
        {
            swap(v[child], v[parent]);
            child = parent;
            parent /= 2;
        }
    }
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> v;
    v.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v.push_back(val);
    }

    buildHeap(v, n + 1);

    for (int i = 1; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}