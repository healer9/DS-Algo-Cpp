//hack.codingblocks.com/app/contests/1211/991/problem
//practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#
//leetcode.com/problems/spiral-matrix/submissions/
#include <iostream>
using namespace std;

void SpiralPrint(int a[][1000], int r, int c)
{
	int sr = 0, sc = 0, er = r - 1, ec = c - 1;
	while (sr <= er && sc <= ec)
	{

		for (int col = sc; col <= ec; col++)
		{
			cout << a[sr][col] << ", ";
		}
		sr++;

		for (int row = sr; row <= er; row++)
		{
			cout << a[row][ec] << ", ";
		}
		ec--;

		if (sr <= er)
		{
			for (int col = ec; col >= sc; col--)
			{
				cout << a[er][col] << ", ";
			}
			er--;
		}
		if (sc <= ec)
		{
			for (int row = er; row >= sr; row--)
			{
				cout << a[row][sc] << ", ";
			}
			sc++;
		}
	}
}

int main()
{
	int b[1000][1000];
	int r, c;
	cin >> r >> c;
	for (int row = 0; row < r; row++)
	{
		for (int col = 0; col < c; col++)
		{
			cin >> b[row][col];
		}
	}
	SpiralPrint(b, r, c);
	cout << "END";
	return 0;
}