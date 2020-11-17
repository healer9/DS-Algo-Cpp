//hack.codingblocks.com/app/contests/1211/416/problem
//leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <iostream>
#include <string>
using namespace std;

class TreeNode
{
public:
    string data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(string d) : data(d), left(NULL), right(NULL) {}
};

TreeNode *createTree()
{
    string s;
    cin >> s;

    if (s == "false")
    {
        return NULL;
    }
    if (s == "true")
    {
        string s;
        cin >> s;
        TreeNode *root = new TreeNode(s);
        root->left = createTree();
        root->right = createTree();
        return root;
    }

    TreeNode *root = new TreeNode(s);
    root->left = createTree();
    root->right = createTree();
    return root;
}

TreeNode *LCA(TreeNode *root, string p, string q)
{
    if (!root or root->data == p or root->data == q)
        return root;

    TreeNode *leftTree = LCA(root->left, p, q);
    TreeNode *rightTree = LCA(root->right, p, q);

    if (leftTree == NULL && rightTree == NULL)
        return NULL;
    if (leftTree != NULL && rightTree != NULL)
        return root;
    return leftTree == NULL ? rightTree : leftTree;

    // one line code --> // return !leftTree ? rightTree : !rightTree ? leftTree : root;
}

int main()
{
    TreeNode *root = createTree();
    string p, q;
    cin >> p >> q;
    cout << LCA(root, p, q)->data;
    return 0;
}