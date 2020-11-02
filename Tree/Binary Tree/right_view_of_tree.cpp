#include <iostream>
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

int max_level = -1;

void right_view_of_tree(node *root, int level)
{
    if (root == NULL)
        return;

    if (level > max_level)
    {
        max_level = level;
        cout << root->data << ", ";
    }

    right_view_of_tree(root->right, level + 1);
    right_view_of_tree(root->left, level + 1);
}

int main()
{
    node *root = createTree();
    right_view_of_tree(root, 0);
    cout << endl;
    return 0;
}