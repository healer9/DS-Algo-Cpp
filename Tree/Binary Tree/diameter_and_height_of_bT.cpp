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

class Pair
{
public:
    int height;
    int diameter;
};

Pair diameterOptimised(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    Pair leftTree = diameterOptimised(root->left);
    Pair rightTree = diameterOptimised(root->right);

    p.height = max(leftTree.height, rightTree.height) + 1;
    p.diameter = max(leftTree.height + rightTree.height, max(leftTree.diameter, rightTree.diameter));

    return p;
}

int main()
{
    node *root = createTree();
    Pair p = diameterOptimised(root);
    cout << "Height of tree = " << p.height;
    cout << "\nDiameter of tree = " << p.diameter;
    cout << endl;
    return 0;
}