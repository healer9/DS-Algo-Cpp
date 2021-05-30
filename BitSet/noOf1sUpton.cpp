//leetcode.com/problems/counting-bits/
//practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
#include <bits/stdc++.h>
using namespace std;

int noOfSetBits(int n)
{
    if (!n)
        return n;

    int msb = (int)log2(n);
    int powOf2 = 1 << msb;
    int countSetBit = ((powOf2 >> 1) * msb) + ((n - powOf2) + 1);
    return countSetBit + noOfSetBits(n - powOf2);
}

int32_t main(int argc, char **argv)
{
    int n;
    cin >> n;
    cout << noOfSetBits(n) << endl;
    return 0;
}