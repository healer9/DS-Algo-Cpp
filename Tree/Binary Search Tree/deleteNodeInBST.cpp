#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : data(data), left(NULL), right(NULL) {}
};

void createBST(TreeNode *root, int data)
{
    if (!root)
    {
        root = new TreeNode(data);
        return;
    }

    root->data > data ? createBST(root->left, data) : createBST(root->right, data);
}

TreeNode *deleteBST(TreeNode *root, int data)
{
    return root;
}

void preOrder(TreeNode *root)
{
    if (!root)
        return;
    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}

int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        TreeNode *root = NULL;
        while (n--)
        {
            int d;
            cin >> d;
            createBST(root, d);
        }
        cin >> n;
        while (n--)
        {
            int data;
            cin >> data;
            root = deleteBST(root, data);
        }

        preOrder(root);
        cout << endl;
    }
    return 0;
}