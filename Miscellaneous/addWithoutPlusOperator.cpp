#include <iostream>
using namespace std;

// for multiplication (a, b) :
// int res = 0
// while(b){
//     if(b & 1)
//         res += a
//     a >>= 1  doulbe a
//     b <<= 1  half b
// }
// return res

// for subtraction (a, b) :
// int borrow = (~a) & b
// a ^= b
// b = borrow << 1

int add(int a, int b)
{
    while (b)
    {
        // cout << "a = " << a << ", b =" << b << endl;
        uint32_t carry = a & b;
        // cout << "carry = " << carry << endl;
        a ^= b;
        b = carry << 1;
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
    return 0;
}