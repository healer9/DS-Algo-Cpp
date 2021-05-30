//leetcode.com/problems/binary-tree-postorder-traversal/
#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *createTree()
{
    int n;
    cin >> n;
    if (n == -1)
        return NULL;
    node *root = new node(n);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void postOrder(node *root)
{
    if (!root)
        return;
    stack<node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        node *temp = st1.top();
        st1.pop();
        st2.push(temp);
        if (temp->left)
            st1.push(temp->left);
        if (temp->right)
            st1.push(temp->right);
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }

    cout << endl;
}

int main()
{
    node *root = createTree();
    postOrder(root);
    return 0;
}