#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

struct node *createNode(struct node *temp, int data)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct node *createList(struct node *head, int data)
{
    if (!head)
    {
        head = createNode(head, data);
        return head;
    }
    struct node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    struct node *newNode;
    temp->next = createNode(newNode, data);
}

void display(struct node *head)
{
    if (!head)
    {
        printf("\nList is empty\n");
        return;
    }

    while (head)
    {
        printf("%d ->", head->data);
        head = head->next;
    }
}

int main()
{
    printf("Enter the number of nodes : ");
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int data;
        scanf("%d", &data);
        head = createList(head, data);
    }

    display(head);

    return 0;
}