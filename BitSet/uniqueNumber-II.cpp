#include <iostream>
#include <math.h>
using namespace std;

unsigned int leftMostSetBit(int Xor)
{
    // -Xor = 2's complement of Xor
    return log2(Xor & -Xor);
}

int main()
{
    int n, Xor = 0;
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        Xor ^= a[i];
    }

    int pos = leftMostSetBit(Xor);

    int mask = 1 << pos;

    int num1 = 0;

    for (int i = 0; i < n; i++)
    {
        if ((mask & a[i]) > 0)
        {
            num1 ^= a[i];
        }
    }
    delete[] a;

    int num2 = Xor ^ num1;

    cout << min(num1, num2) << " " << max(num1, num2) << endl;
    return 0;
}