//leetcode.com/problems/rotate-image/
#include <iostream>
#include <vector>
using namespace std;

void rotate90(vector<vector<int>> &matrix)
{
    int size = matrix.size();

    int start = 0, end = size - 1;
    while (start < end)
    {
        for (int j = 0; j < size; j++)
        {
            swap(matrix[start][j], matrix[end][j]);
        }
        start++;
        end--;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (i != j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row);
    for (int i = 0; i < row; i++)
        matrix[i].resize(col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> matrix[i][j];
    }

    rotate90(matrix);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}