//hack.codingblocks.com/app/contests/1211/175/problem

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtEnd(node *&head, int data)
{
    if (!head)
    {
        head = new node(data);
        return;
    }
    node *temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = new node(data);
}

void removeDuplicate(node *&head)
{
    if (!head or !head->next)
        return;

    node *curr = head;
    while (curr)
    {
        node *temp = curr->next;
        while ((temp) and (temp->data == curr->data))
        {
            node *del = temp;
            temp = temp->next;
            curr->next = temp;
            delete del;
        }
        curr = curr->next;
    }

    // return head;
}

void print(node *head)
{
    if (!head)
        return;
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        node *head = NULL;
        int n;
        cin >> n;
        while (n--)
        {
            int d;
            cin >> d;
            insertAtEnd(head, d);
        }

        removeDuplicate(head);

        print(head);
    }
    return 0;
}