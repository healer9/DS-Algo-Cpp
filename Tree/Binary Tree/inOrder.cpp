//leetcode.com/problems/binary-tree-inorder-traversal/
#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    int n;
    cin >> n;
    if (n == -1)
        return NULL;
    Node *root = new Node(n);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void inOrder(Node *root)
{
    if (!root)
        return;
    stack<Node *> st;
    st.push(root);

    Node *curr = root;
    while (!st.empty())
    {
        if (curr == NULL)
        {
            Node *temp = st.top();
            st.pop();
            cout << temp->data << " ";
            curr = temp->right;
            if (curr)
                st.push(curr);
        }
        else
        {
            curr = curr->left;
            if (curr)
                st.push(curr);
        }
    }

    cout << endl;
}

int main()
{
    Node *root = createTree();
    inOrder(root);
    return 0;
}