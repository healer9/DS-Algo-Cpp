// Coding Block Question
// Sample Input 4 1 2 3 4 5 6 7 - 1 - 1 - 1 - 1 - 1 8 - 1 9 - 1 - 1 - 1 - 1
// n = 4
// input is given as level order of a tree

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// take input when it is given as "level order of a tree" fashion
Node *createLevelOrderTree()
{
    int d;
    cin >> d;
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            f->left = new Node(c1);
            q.push(f->left);
        }

        if (c2 != -1)
        {
            f->right = new Node(c2);
            q.push(f->right);
        }
    }
    return root;
}

// ---------------Method 1-----------------

// void getVerticalOrder(Node *root, int hd, map<int, vector<int>> &m)
// {
//     // Base case
//     if (root == NULL)
//         return;

//     // Store current node in map 'm'
//     m[hd].push_back(root->data);

//     // Store nodes in left subtree
//     getVerticalOrder(root->left, hd - 1, m);

//     // Store nodes in right subtree
//     getVerticalOrder(root->right, hd + 1, m);
// }
// void printVerticalOrder(Node *root)
// {
//     // Create a map and store vertical oder in map using
//     // function getVerticalOrder()
//     map<int, vector<int>> m;
//     int hd = 0;
//     getVerticalOrder(root, hd, m);

//     // Traverse the map and print nodes at every horigontal
//     // distance (hd)
//     map<int, vector<int>>::iterator it;
//     for (it = m.begin(); it != m.end(); it++)
//     {
//         for (int i = 0; i < it->second.size(); ++i)
//             cout << it->second[i] << " ";
//         cout << endl;
//     }
// }

// ------------------------------Method 2-----------------------------

void dfs(Node *root, int r, int c, unordered_map<int, vector<pair<int, int>>> &cache, int &minCol, int &maxCol)
{
    if (!root)
        return;

    if (cache.count(c))
        cache[c].push_back({r, root->data});
    else
        cache.insert({c, {{r, root->data}}});

    minCol = min(minCol, c);
    maxCol = max(maxCol, c);

    dfs(root->left, r + 1, c - 1, cache, minCol, maxCol);
    dfs(root->right, r + 1, c + 1, cache, minCol, maxCol);
}

// vertical order of a tree
vector<vector<int>> verticalOrderPrint(Node *root)
{
    vector<vector<int>> result;

    if (!root)
        return result;

    unordered_map<int, vector<pair<int, int>>> cache;
    int minCol = 0, maxCol = 0;

    dfs(root, 0, 0, cache, minCol, maxCol);

    for (int c = minCol; c <= maxCol; c++)
    {
        sort(cache[c].begin(), cache[c].end(), [](pair<int, int> &p1, pair<int, int> &p2) {
            return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
        });
        vector<int> col;
        for (pair<int, int> &p : cache[c])
        {
            col.push_back(p.second);
        }
        result.push_back(col);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    Node *root = createLevelOrderTree();

    vector<vector<int>> ans = verticalOrderPrint(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}