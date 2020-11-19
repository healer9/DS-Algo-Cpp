#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtEnd(Node *&head, int data)
{
    if (!head)
    {
        head = new Node(data);
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

void print(Node *head)
{
    if (!head)
        return;
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

Node *getMid(Node *head)
{
    Node *mid = head;
    Node *aHead = head->next;
    while (aHead && aHead->next)
    {
        mid = mid->next;
        aHead = aHead->next->next;
    }
    return mid;
}

Node *merge(Node *h1, Node *h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;

    if (h1->data < h2->data)
    {
        h1->next = merge(h1->next, h2);
        return h1;
    }
    else
    {
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

Node *mergeSort(Node *&head)
{
    if (!head || !head->next)
        return head;
    Node *h1 = head;
    Node *mid = getMid(head);
    Node *h2 = mid->next;
    mid->next = NULL;

    mergeSort(h1);
    mergeSort(h2);

    return merge(h1, h2);
}

int main()
{
    int n;
    cin >> n;
    Node *head = NULL;

    while (n--)
    {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }

    head = mergeSort(head);

    print(head);

    return 0;
}