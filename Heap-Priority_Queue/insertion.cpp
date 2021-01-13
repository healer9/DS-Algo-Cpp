#include <iostream>
#include <vector>
using namespace std;

class Heap
{
    vector<int> data;
    bool minHeap;

public:
    Heap(bool type)
    {
        data.push_back(-1);
        minHeap = type;
    }
    void reorderMax(bool type)
    {
        int pos = data.size() - 1;
        if (type)
        {
            while (pos > 1)
            {
                if (data[pos] < data[pos / 2])
                {
                    swap(data[pos], data[pos / 2]);
                    pos /= 2;
                }
                else
                    break;
            }
        }
        else
        {
            while (pos > 1)
            {
                if (data[pos] > data[pos / 2])
                {
                    swap(data[pos], data[pos / 2]);
                    pos /= 2;
                }
                else
                    break;
            }
        }
    }
    void heapify(int pos)
    {
        // cout << pos << endl;
        if ((data[pos] < data[2 * pos]) and (data[pos] < data[2 * pos + 1]))
            return;
        if (((2 * pos) >= data.size()) or ((2 * pos + 1) >= data.size()))
            return;
        if (data[2 * pos] < data[2 * pos + 1])
        {
            // cout << data[pos] << " " << data[2 * pos] << endl;
            swap(data[pos], data[2 * pos]);
            heapify(2 * pos);
        }
        else
        {
            // cout << data[pos] << " " << data[2 * pos + 1] << endl;
            swap(data[pos], data[2 * pos + 1]);
            heapify(2 * pos + 1);
        }
    }
    void push(int val)
    {
        data.push_back(val);
        reorderMax(minHeap);
    }
    void pop()
    {
        if (data.size() > 1)
        {
            int last = data.size() - 1;
            swap(data[1], data[last]);
            data.pop_back();
            // viewHeap();
            heapify(1);
        }
        else
            return;
    }
    int top()
    {
        return !data.empty() ? data[1] : -1;
    }
    void viewHeap()
    {
        for (int i = 1; i < data.size(); i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main(int argc, char *argv[])
{
    // for min heap make constructor parameter = true
    // for max heap make constructor parameter = false
    int ch;
    cout << "Type of heap (for min enter '0' for max enter '1'): ";
    cin >> ch;

    bool type = true;

    if (ch)
        type = false;

    Heap pq(type);

    int q;
    cin >> q;

    while (q--)
    {
        int op, val;
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> val;
            pq.push(val);
            pq.viewHeap();
            break;
        case 2:
            pq.pop();
            pq.viewHeap();
            break;
        default:
            pq.viewHeap();
        }
    }

    // pq.push(1);
    // pq.push(2);
    // pq.push(3);
    // pq.push(17);
    // pq.push(19);
    // pq.push(36);
    // pq.push(7);
    // pq.push(25);
    // pq.push(100);
    // pq.viewHeap();
    // pq.push(0);
    // pq.viewHeap();
    // pq.pop();
    // pq.viewHeap();
    return 0;
}