// https: //hack.codingblocks.com/app/contests/1211/223/problem

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottomOfStack(stack<int> &s, int last)
{
    if (s.empty())
    {
        s.push(last);
        return;
    }

    int temp = s.top();
    s.pop();

    insertAtBottomOfStack(s, last);

    s.push(temp);
}

void reverseStackRec(stack<int> &s)
{
    if (s.size() == 1)
        return;

    int data = s.top();
    s.pop();
    reverseStackRec(s);

    insertAtBottomOfStack(s, data);
}

using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> s;
    while (n--)
    {
        int d;
        cin >> d;
        s.push(d);
    }

    reverseStackRec(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}