#include <iostream>
#include <queue>
using namespace std;

void recReverse(queue<int> &q)
{
    if (q.empty())
        return;

    int data = q.front();
    q.pop();

    recReverse(q);
    q.push(data);
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    queue<int> q;

    while (n--)
    {
        int data;
        cin >> data;
        q.push(data);
    }

    recReverse(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}