//leetcode.com/problems/binary-tree-preorder-traversal/
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

void preOrder(node *root)
{
    if (!root)
        return;
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
    cout << endl;
}

int main()
{
    node *root = createTree();
    preOrder(root);
    return 0;
}