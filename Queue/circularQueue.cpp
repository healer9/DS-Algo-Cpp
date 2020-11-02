// https: //hack.codingblocks.com/app/contests/1211/1025/problem

#include <iostream>
using namespace std;

class MyCircularQueue
{
    int *a;
    int f;
    int r;
    int size;
    int currentSize;

public:
    MyCircularQueue(int s)
    {
        a = new int[s];
        f = 0;
        size = s;
        r = size - 1;
        currentSize = 0;
    }

    int Front()
    {
        return currentSize == 0 ? -1 : a[f];
    }

    int Rear()
    {
        return currentSize == 0 ? -1 : a[r];
    }

    bool enQueue(int val)
    {
        if (isFull())
            return false;

        r = (r + 1) % size;

        a[r] = val;
        currentSize++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;

        f = (f + 1) % size;
        currentSize--;
        return true;
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    bool isFull()
    {
        return currentSize == size;
    }
};

int main()
{
    int size, data;
    cin >> size;

    MyCircularQueue q(size);

    while (1)
    {
        int ch;
        cin >> ch;

        if (ch < 1 or ch > 6)
            break;

        switch (ch)
        {
        case 1:
            cin >> data;
            if (q.enQueue(data))
                cout << "true\n";
            else
                cout << "false\n";
            break;
        case 2:
            if (q.deQueue())
                cout << "true\n";
            else
                cout << "false\n";
            break;
        case 3:
            cout << q.Front() << endl;
            break;
        case 4:
            cout << q.Rear() << endl;
            break;
        case 5:
            if (q.isEmpty())
                cout << "true\n";
            else
                cout << "false\n";
            break;
        case 6:
            if (q.isFull())
                cout << "true\n";
            else
                cout << "false\n";
            break;
        }
    }

    return 0;
}