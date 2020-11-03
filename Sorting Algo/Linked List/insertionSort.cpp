//hack.codingblocks.com/app/contests/1211/166/problem

#include <iostream>
#include <climits>
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

// insertion Sort in a LinkedList

Node *insertionSort(Node *head)
{
    if (!head or !head->next)
        return head;
    Node *dummy = new Node(INT_MIN);

    dummy->next = head;

    Node *curr = head;
    Node *pre = dummy;

    while (curr)
    {
        if ((curr->next) and (curr->next->data < curr->data))
        {
            while ((pre->next) and (pre->next->data < curr->next->data))
            {
                pre = pre->next;
            }

            Node *temp = pre->next;
            pre->next = curr->next;
            curr->next = curr->next->next;
            pre->next->next = temp;
            pre = dummy;
        }
        else
        {
            curr = curr->next;
        }
    }

    return dummy->next;
}

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

    head = insertionSort(head);

    print(head);

    return 0;
}