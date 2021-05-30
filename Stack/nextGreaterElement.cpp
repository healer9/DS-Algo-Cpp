//practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
#include "bits/stdc++.h"
using namespace std;

#define int long long

vector<int> nextGreaterElement(vector<int> element, int n)
{
    vector<int> NGE(n);
    stack<int> s;
    s.push(0);

    for (int i = 1; i < n; i++)
    {
        if (element[s.top()] < element[i])
        {
            while (!s.empty() and element[s.top()] < element[i])
            {
                NGE[s.top()] = element[i];
                s.pop();
            }
        }
        s.push(i);
    }

    while (!s.empty())
    {
        NGE[s.top()] = -1;
        s.pop();
    }

    return NGE;
}

vector<int> nextSmallerElement(vector<int> element, int n)
{
    vector<int> NSE(n);
    stack<int> s;
    s.push(0);

    for (int i = 1; i < n; i++)
    {
        if (element[s.top()] > element[i])
        {
            while (!s.empty() and element[s.top()] > element[i])
            {
                NSE[s.top()] = element[i];
                s.pop();
            }
        }
        s.push(i);
    }

    while (!s.empty())
    {
        NSE[s.top()] = -1;
        s.pop();
    }

    return NSE;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> element(n);
    for (int &i : element)
        cin >> i;

    vector<int> NGE = nextGreaterElement(element, n);

    for (int i : NGE)
        cout << i << " ";
    cout << endl;

    vector<int> NSE = nextSmallerElement(element, n);

    for (int i : NSE)
        cout << i << " ";
    cout << endl;

    return 0;
}