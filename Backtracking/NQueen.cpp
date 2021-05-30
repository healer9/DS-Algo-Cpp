#include <iostream>
using namespace std;

bool possible(int chessBoard[][10], int i, int j)
{
    // check above
    for (int row = i; row >= 0; row--)
    {
        if (chessBoard[row][j])
            return false;
    }

    // check left
    for (int col = j; col >= 0; col--)
    {
        if (chessBoard[i][col])
            return false;
    }

    // check along diagonal
    for (int row = i, col = j; row >= 0 and col >= 0; row--, col--)
    {
        if (chessBoard[row][col])
            return false;
    }

    return true;
}

void nQueen(int chessBoard[][10], int row, int col, int i, int j)
{
    if (i == row)
        return;

    if (j == col)
    {
        i++;
        j = 0;
    }

    if (possible(chessBoard, i, j))
    {
        chessBoard[i][j] = 1;
        nQueen(chessBoard, row, col, i, j + 1);
    }

    chessBoard[i][j] = 0;
}

int main(int argc, char *argv[])
{
    int boardSize;
    cin >> boardSize;

    int chessBoard[10][10] = {0};

    nQueen(chessBoard, boardSize, boardSize, 0, 0);

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (chessBoard[i][j])
                cout << "Q ";
            else
                cout << "_ ";
        }
        cout << endl;
    }

    return 0;
}