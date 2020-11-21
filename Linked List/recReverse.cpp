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
        temp = temp->next;

    temp->next = new Node(data);
}

Node *recReverse(Node *head)
{
    if (!head or !head->next)
        return head;

    Node *sHead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return sHead;
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
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    while (n--)
    {
        int d;
        cin >> d;
        insertAtEnd(head, d);
    }

    head = recReverse(head);
    print(head);
    return 0;
}