//hack.codingblocks.com/app/contests/1289/338/problem

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *help(node *root, int data)
{
    if (root == NULL)
        return new node(data);

    if (data <= root->data)
        root->left = help(root->left, data);
    else
        root->right = help(root->right, data);

    return root;
}

node *BST()
{
    int data, n;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        root = help(root, data);
    }
    return root;
}

void countNodes(node *root, int &nodes)
{
    if (!root)
        return;
    nodes++;
    countNodes(root->left, nodes);
    countNodes(root->right, nodes);
}

void findMedian(node *root, int &n1, int &k)
{
    if (!root)
        return;
    findMedian(root->left, n1, k);
    k--;
    if (k == 0)
    {
        n1 = root->data;
        return;
    }
    findMedian(root->right, n1, k);
}

int main()
{
    node *root = BST();
    int nodes = 0;
    countNodes(root, nodes);
    // cout<<nodes<<endl;
    int n1 = 0, n2 = 0;
    bool odd = (nodes & 1) ? 1 : 0;

    int k = (nodes + 1) / 2;
    findMedian(root, n1, k);
    if (!odd)
    {
        k = ((nodes + 1) / 2) + 1;
        findMedian(root, n2, k);
    }
    (nodes & 1) ? cout << n1 : cout << (n1 + n2) / 2;
    return 0;
}