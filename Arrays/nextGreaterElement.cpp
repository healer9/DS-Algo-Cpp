//leetcode.com/problems/next-greater-element-i/submissions/
//leetcode.com/problems/next-greater-element-ii/
//leetcode.com/problems/next-greater-element-iii/
#include <bits/stdc++.h>
using namespace std;

void nextGreaterElement(vector<int> &a, vector<int> &greaterElements)
{
    const int size = a.size();
    stack<int> index;
    index.push(0);
    for (int i = 1; i < size; i++)
    {
        if (a[i] <= a[index.top()])
            index.push(i);
        else
        {
            while (!index.empty() and a[i] >= a[index.top()])
            {
                greaterElements[index.top()] = a[i];
                index.pop();
            }
            index.push(i);
        }
    }
    while (!index.empty())
    {
        greaterElements[index.top()] = -1;
        index.pop();
    }
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<int> greaterElements(n, 0);
    nextGreaterElement(a, greaterElements);
    for (int i : greaterElements)
        cout << i << " ";
    cout << endl;
    return 0;
}