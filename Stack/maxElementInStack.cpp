//www.hackerrank.com/challenges/maximum-element/problem
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q;
    cin >> Q;
    stack<int> st;

    while (Q--)
    {
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            int d;
            cin >> d;
            if (st.empty())
                st.push(d);
            else
                st.push(max(d, st.top()));
            break;
        case 2:
            if (!st.empty())
                st.pop();
            break;
        case 3:
            cout << st.top() << endl;
            break;
        }
    }
    return 0;
}