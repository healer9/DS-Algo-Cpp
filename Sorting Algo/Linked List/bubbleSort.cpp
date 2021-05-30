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

Node *insertAtEnd(Node *head, int d)
{
    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new Node(d);
    return head;
}

void print(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void bubbleSort(Node *head, int n)
{

    for (int i = 0; i < n; i++)
    {
        Node *prev = head;
        Node *curr = head->next;

        while (curr and curr->next)
        {

            Node *aHead = curr->next;

            if (curr->data > aHead->data)
            {
                prev->next = aHead;
                curr->next = aHead->next;
                aHead->next = curr;
            }
            else
            {
                curr = curr->next;
            }
            prev = prev->next;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int m = n;
    Node *head = new Node(-1);

    while (m--)
    {
        int d;
        cin >> d;
        head = insertAtEnd(head, d);
    }

    bubbleSort(head, n);
    print(head->next);

    return 0;
}