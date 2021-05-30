//leetcode.com/problems/unique-paths-ii/
#include <iostream>
#include <vector>
using namespace std;

// obstacleGrid[i][j] == 1 means obstacle at (i,j)
// obstacleGrid[i][j] == 0 means grid is empty (i,j) traverseable

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    if (obstacleGrid[0][0] == 1)
        return 0;

    obstacleGrid[0][0] = 1;

    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();

    int dp[100][100];

    for (int j = 1; j < col; j++)
    {
        if (obstacleGrid[0][j] == 1)
            obstacleGrid[0][j] = 0;
        else
            obstacleGrid[0][j] = obstacleGrid[0][j - 1];
    }

    for (int i = 1; i < row; i++)
    {
        if (obstacleGrid[i][0] == 1)
            obstacleGrid[i][0] = 0;
        else
            obstacleGrid[i][0] = obstacleGrid[i - 1][0];
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (obstacleGrid[i][j] == 1)
                obstacleGrid[i][j] = 0;
            else
                obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
        }
    }

    return obstacleGrid[row - 1][col - 1];
}

int main(int argc, char *argv[])
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> obstacleGrid(row);
    for (int i = 0; i < row; i++)
        obstacleGrid[i].resize(col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> obstacleGrid[i][j];
    }

    cout << uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}
