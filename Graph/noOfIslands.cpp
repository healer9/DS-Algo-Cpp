//leetcode.com/problems/number-of-islands/
//gist.github.com/SuryaPratapK/a494ad5194ea33ee83b343698c1fa98e
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int xCoordinate, int yCoordinate, int &row, int &col)
{
    if (xCoordinate < 0 || yCoordinate < 0 || xCoordinate >= row || yCoordinate >= col)
        return;
    if (graph[xCoordinate][yCoordinate] != 1)
        return;

    graph[xCoordinate][yCoordinate] = -1;
    dfs(graph, xCoordinate - 1, yCoordinate, row, col);
    dfs(graph, xCoordinate, yCoordinate - 1, row, col);
    dfs(graph, xCoordinate + 1, yCoordinate, row, col);
    dfs(graph, xCoordinate, yCoordinate + 1, row, col);
}

int noOfIslands(vector<vector<int>> &graph)
{
    int noOfIslands = 0;
    int row = graph.size();
    int col = graph[0].size();
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (graph[i][j] == 1)
            {
                noOfIslands++;
                dfs(graph, i, j, row, col);
            }
        }
    }
    return noOfIslands;
}

int main(int argc, char *argv[])
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> graph(row);
    for (int i = 0; i < graph.size(); i++)
    {
        graph[i].resize(col);
        for (int j = 0; j < graph[i].size(); j++)
            cin >> graph[i][j];
    }

    cout << noOfIslands(graph) << endl;

    // for (int i = 0; i < graph.size(); i++)
    // {
    //     for (int j = 0; j < graph[i].size(); j++)
    //         cout << graph[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}